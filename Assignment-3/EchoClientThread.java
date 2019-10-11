/**
 * Name: Jash Patel
 * Summary: This program is designed to let user input data, then the data is send to server and 
 *          the server return the data back. This program is an example of network socket programming.
 *          The program will terminate once user enter ".".
 */
import java.net.*;
import java.io.*;
import java.util.*;

public class EchoClientThread {
	private static String localhost;

	public static void main(String[] args) {
        
		//Checks if user inputs correct command format
		//if (args.length != 1) {
		//	System.out.println("Usage:java Echoclient localhost");
		//	System.exit(0);
		//}
		
		//localhost = args[0]; 

		try {
			//Create localhost connection
			Socket connection = new Socket(localhost, 12345);
            //Create input and output objects
			InputStream dataInput = connection.getInputStream();
			OutputStream dataOutput = connection.getOutputStream();
			//Create scanner to read user input
			Scanner sc = new Scanner(System.in);

			/**
			 * Store user input to buffer array and send the data to server. 
			 * Then print the data sent by server
			 */
			
			while (true) {
				String readInput = sc.nextLine();

				byte[] buffer = readInput.getBytes();
				if (readInput.equals(".")) {
					connection.close(); //Close the connection
					break;

				}
				else {

					dataOutput.write(buffer); //Send the data to server
					dataOutput.flush();        //Forces buffered output bytes to be written

					
					// Read input data from server
					byte[] outputData = new byte[1024];
					int serverInput = dataInput.read(outputData);

					String convertToString = new String(outputData);
					System.out.println("Server: " + convertToString);
				}
			}
			//Close Connection
			dataInput.close();
			dataOutput.close();

		} catch (IOException e) {
			//do nothing

		}

	}

}
