import pandas as pd
import sqlite3 as s
names = ['book_dimension', 'warehouse_dimension', 'location_dimension', 'price_list', 'customer_dimension', 'ship_mode_dimension']
query = 'SELECT * FROM '


def create_db():
	csv_db = s.connect('data/csv_db')
	book_dimension = pd.read_csv('various-sources/Book_Dimensions.csv', index_col = 'book_key')
	book_dimension.to_sql('book_dimension', csv_db, if_exists = 'replace')

	warehouse_dimension = pd.read_csv('various-sources/Warehouse_Dimensions.csv', index_col = 'warehouse_key')
	warehouse_dimension.to_sql('warehouse_dimension', csv_db, if_exists = 'replace')
	csv_db.close()

	txt_db = s.connect('data/txt_db')
	location_dimension = pd.read_csv('various-sources/Location_Dimensions.txt',sep = '\t', index_col = 'location_key')
	location_dimension.to_sql('location_dimension', txt_db, if_exists = 'replace')

	price_list = pd.read_csv('various-sources/Price_List.txt',sep = '\t', index_col = 'price_key')
	price_list.to_sql('price_list', txt_db, if_exists = 'replace')
	txt_db.close()

	xlsx_db = s.connect('data/xlsx_db')
	customer_dimension = pd.read_excel('various-sources/Customer_Dimensions.xlsx', sheet_name = 'Sheet1', index_col = 'cust_key')
	customer_dimension.to_sql('customer_dimension', xlsx_db, if_exists = 'replace')

	ship_mode_dimension = pd.read_excel('various-sources/Ship_Mode_Dimensions.xlsx', sheet_name = 'Sheet1', index_col = 'ship_mode_key')
	ship_mode_dimension.to_sql('ship_mode_dimension', xlsx_db, if_exists = 'replace')
	xlsx_db.close()


def extract_db():
	df = []
	db = s.connect('data/csv_db')
	df.append(pd.read_sql_query(query + 'book_dimension', db))
	df.append(pd.read_sql_query(query + 'warehouse_dimension', db))
	db.close()
	db = s.connect('data/txt_db')
	df.append(pd.read_sql_query(query + 'location_dimension', db))
	df.append(pd.read_sql_query(query + 'price_list', db))
	db.close()
	db = s.connect('data/xlsx_db')
	df.append(pd.read_sql_query(query + 'customer_dimension', db))
	df.append(pd.read_sql_query(query + 'ship_mode_dimension', db))
	db.close()

	db = s.connect('data/common_db')
	for i, frame in enumerate(df):
		frame.to_sql(names[i], db, if_exists = 'replace')
	db.close()

choice = 1
while choice < 5 and choice > 0 :
	choice = int(input('\nEnter your choice: \n1.Create Database\n2.Extract into common Database\n3.Display Common Database\n4.Delete All Databases\n5.Exit\n>> '))
	if choice == 1:
		create_db()
		print('Databases Created!')
	elif choice == 2:
		try:
			extract_db()
			print('Databases Extracted!')
		except:
			print('No databases found!')
	elif choice == 3:
		try:
			db = s.connect('data/common_db')
			for table_name in names:
				print('\n\n')
				print(pd.read_sql_query(query + table_name, db))
			if db:
				db.close()
			print('Common Database deleted!')
		except:
			print('No common database found!')
	elif choice == 4:
		from subprocess import call
		call('del /q "data\\*"', shell = True)
	else:
		print('Quiting..')
