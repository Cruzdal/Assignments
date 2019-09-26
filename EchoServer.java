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
				
				//DataInputStream dataInput = new DataInputStream(clientSocket.getInputStream());
				OutputStream dataOutput = clientSocket.getOutputStream();
				//InputStreamReader clientInput = new InputStreamReader(System.in);
	          //  BufferedReader buffer = new BufferedReader(clientInput);
	           
				//Scanner sc = new Scanner(System.in);
	            String strIn="",strOut="";
	         while (true) {   
				byte[] buffer = new byte[1024];
			
				int readInput = dataInput.read(buffer, 0, buffer.length);
				 
				
				String convertToString= "";
				if(readInput !=-1) {
					 convertToString = new String(buffer);
					System.out.println(convertToString);
					//strOut=buffer.readLine();
					
				}
				else {
					break;
				}
				dataOutput.write(buffer);
				dataOutput.flush();
				
				//int readInput = dataInput.read(inputStr, 0, inputStr.length);
			//	int writeOutput = serverOutput.write(inputStr,0,inputStr.length);
				//System.out.println(Integer.toString(readInput));
				/*while (!strIn.equals(".")) {
					strIn = dataInput.readUTF();
					System.out.println(strIn);
					strOut=buffer.readLine();
					System.out.println(strOut);

					dataOutput.writeUTF(strIn);
					dataOutput.flush();
					
					
				/*	if (readInput == -1) {
						break;
					}*/
				//}
			
				dataInput.close();
				clientSocket.close();
				serverSocket.close();
	         }

		} catch (IOException e) {
			System.err.println("Server Disconnected");

		}
	}
}