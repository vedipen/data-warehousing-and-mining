import java.util.*;
import java.io.*;

public class Main {
	public static HashMap<String, String> dataset = new HashMap<String, String>();
	public static void main(String args[]) throws IOException {
		FileInputStream fstream = new FileInputStream("dataset");	
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
		String line = br.readLine();
		while(line.length()!=0) {		
			addToDataset(line);
			line = br.readLine();
		}
	}

	public static void addToDataset(String line) {
		StringTokenizer input = new StringTokenizer(line);
		dataset.put(input.nextToken(),input.nextToken());
	}

	public static void printDataset() {
		
	}
	
}
