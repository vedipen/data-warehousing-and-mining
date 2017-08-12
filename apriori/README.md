# Apriori Algorithm with Association Rules

### Run
`make Apriori`  
`./Apriori`

### Needs
* GCC C++14 installed
* A database file (with format : `TransactionName TransactionItem1,TransactionItem2,..`)
* File read access to user

### Output
For input file - '/database'

```
Enter minimum support % : 30        
Enter minimum confidence % : 60

Total Transactions : 18
Support is 5

C1 --->

Item Set		Support Count
-------------------------------------------
CPU			13
Cover			3
Monitor			12
Mouse			14
Webcam			4


L1 --->

Item Set		Support Count
-------------------------------------------
CPU			13
Monitor			12
Mouse			14


C2 --->

Item Set		Support Count
-------------------------------------------
CPU,Monitor			9
CPU,Mouse			9
Monitor,Mouse			8


L2 --->

Item Set		Support Count
-------------------------------------------
CPU,Monitor			9
CPU,Mouse			9
Monitor,Mouse			8


C3 --->

Item Set		Support Count
-------------------------------------------
CPU,Monitor,Mouse			5


L3 --->

Item Set		Support Count
-------------------------------------------
CPU,Monitor,Mouse			5


Association rule for CPU,Monitor,Mouse --->

Association Rule		Support		Confidence		Confidence %
--------------------------------------------------------------------------------------------
CPU^Monitor => Mouse			5		5/9 = 0.56		56
Monitor^Mouse => CPU			5		5/8 = 0.62		62
CPU^Mouse => Monitor			5		5/9 = 0.56		56
Mouse => CPU^Monitor			5		5/14 = 0.36		36
CPU => Monitor^Mouse			5		5/13 = 0.38		38
Monitor => CPU^Mouse			5		5/12 = 0.42		42


Minimum confidence % is 60%

Association Rule			Support		Confidence %
---------------------------------------------------------------------
Monitor^Mouse=>CPU				5		62


Final Association Rules for Market-Basket Analysis are :
Monitor^Mouse=>CPU


```
