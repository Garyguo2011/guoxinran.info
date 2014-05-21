import java.net.*;
import java.io.*;
import java.util.Scanner;

class Generator{
	private String name;
	private String description;

/*	public static String readFileContent(){
		FileReader reader = new FileReader("/Users/GaryGuo/Dropbox/JavaTest/java/index.php");
        BufferedReader fileIn = new BufferedReader(reader);
        String dataLine = fileIn.readLine();
        System.out.println(dataLine);
        return dataLine;
    }
*/
/*
	public static void createFile(){
		String fileName = "";
		Scanner scnr = new Scanner (System.in);
		
		System.out.println("Enter your File name here:");

		fileName = scnr.next();
		if (!fileName.equals("")){
			File fileExample = new File(fileName);
			PrintWriter pwInput = new PrintWriter(fileExample);
			pwInput.println("this is first time to generate PHP file by using java");
			pwInput.close();
			System.out.println("file have been created");
		}
	}
*/
	public static void main(String[] args) {
		String text = "whaterever";
        try {
/*        File file = new File("index.php");
          BufferedWriter output = new BufferedWriter(new FileWriter(file));
          output.write(text);
          output.close();
*/
        	FileReader reader = new FileReader("index.php");
        	BufferedReader fileIn = new BufferedReader(reader);
        	
        	
        	String dataLine = fileIn.readLine();
        	while(dataLine != null){
        		dataLine = fileIn.readLine();
        		System.out.println(dataLine);	
        	}
        	

        } catch ( IOException e ) {
           e.printStackTrace();
        }
   	}
}