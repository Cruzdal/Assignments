import java.net.*;
import java.io.*;
import java.util.*;

public class EchoClient {
	private static String localhost;

	public static void main(String[] args) {
		 try  {
			 localhost= args[0];
			}
			catch (Exception e){
	                 System.out.println("Usage:java Echoclient localhost");
			}

		try {

			Socket connection = new Socket(localhost, 50);
			InputStream dataInput = connection.getInputStream();
			OutputStream dataOutput = connection.getOutputStream();
			Scanner sc = new Scanner(System.in);

		
			while (true) {
				String readInput = sc.nextLine();

				byte[] buffer = readInput.getBytes();
		
				if (readInput.equals(".")) {
	
					connection.close();
					break;

				}

				else {

					dataOutput.write(buffer);
					dataOutput.flush();
					// Read input data from server
					byte[] outputData = new byte[1024];
					int strIn = dataInput.read(outputData);
					// System.out.println(outputData);

					String convertToString = new String(outputData);
					System.out.println("Server: " + convertToString);
					// dataOutput.flush();

				}
			}


			dataInput.close();
			dataOutput.close();
			connection.close();

		} catch (IOException e) {
			System.err.println("Client Disconnected");

		}

	}

}