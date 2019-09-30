import java.net.*;
import java.util.Scanner;
import java.io.*;

public class EchoServer {
	public static void main(String[] args) {

		try {

				ServerSocket serverSocket = new ServerSocket(50);

			
				System.out.println("server waiting, use cntl-C to quit\n");
				Socket clientSocket = serverSocket.accept();
				System.out.println("server connected");
				
				InputStream dataInput = clientSocket.getInputStream();
				OutputStream dataOutput = clientSocket.getOutputStream();
			
	         while (true) {   
				byte[] buffer = new byte[1024];
			
				int readInput = dataInput.read(buffer, 0, buffer.length);
				 
				
				String convertToString= "";
				if(readInput !=-1) {
					 convertToString = new String(buffer);
					System.out.println(convertToString);
			
				}
				else {
					break;
				}
				dataOutput.write(buffer);
				dataOutput.flush();
			
			
				dataInput.close();
				clientSocket.close();
				serverSocket.close();
	         }

		} catch (IOException e) {
			System.err.println("Server Disconnected");

		}
	}
}