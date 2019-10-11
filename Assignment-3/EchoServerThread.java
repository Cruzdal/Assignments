/**
 * Name: Jash Patel
 * Summary: This program is designed to receive data from client server and then sends the same 
 * 			data back to the client.
 */
import java.net.*;
import java.util.Scanner;
import java.io.*;

public class EchoServerThread {
	private static Thread thread;
	private static ServerSocket serverSocket;
	private static ClientHandler clientHandler;
	public static void main(String[] args) {

		try {
            //Create a connection for a server
			serverSocket = new ServerSocket(12345);
			//Accept the connection at port 12345
			//Socket clientSocket = serverSocket.accept();
            
			//Create input and output objects
			//InputStream dataInput = clientSocket.getInputStream();
			//OutputStream dataOutput = clientSocket.getOutputStream();
			while (true) {
				//Socket clientSocket = serverSocket.accept();
				//InputStream dataInput = clientSocket.getInputStream();
				//OutputStream dataOutput = clientSocket.getOutputStream();
				
				clientHandler =new ClientHandler(serverSocket.accept());
				thread = new Thread (clientHandler);
				thread.start();
				
			}
		//	serverSocket.close();
			//While connection is available send input data back to client 
		/*	while (true) {
				//Declare buffer array to store input data
				byte[] buffer = new byte[1024];
				//Read input data by storing input data into buffer
				int readInput = dataInput.read(buffer, 0, buffer.length);

				String convertToString = "";
				
				//Convert input data to string before reached end of socket connection 
				if (readInput != -1) {
					convertToString = new String(buffer);
				} else {
					break; //Break out of loop when reached end of socket connection
				}
				dataOutput.write(buffer);  //Write the data back to client
				dataOutput.flush();        //Forces buffered output bytes to be written

			}
			//Close the socket connection
			dataInput.close();
			clientSocket.close();*/
			

		} catch (IOException e) {
			// do nothing

		}
	}
}
