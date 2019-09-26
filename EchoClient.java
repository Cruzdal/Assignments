import java.net.*;
import java.io.*;
import java.util.*;

public class EchoClient {
	private static String localhost;

	public static void main(String[] args) {

		// localhost= args[0];
		try {

			Socket connection = new Socket(localhost, 50);
			// DataInputStream dataInput = new DataInputStream(connection.getInputStream());
			InputStream dataInput = connection.getInputStream();
			OutputStream dataOutput = connection.getOutputStream();
			// InputStream inputStr = connection.getInputStream();
			Scanner sc = new Scanner(System.in);
			// InputStreamReader clientInput = new InputStreamReader(System.in);

			// BufferedReader buffer = new BufferedReader(clientInput);
			// BufferedWriter buffWriter = new BufferedWriter(buffWriter);
			// Read the user input string

			// String input = clientStr.toString();
			while (true) {
				String readInput = sc.nextLine();

				byte[] buffer = readInput.getBytes();
				// String convertToString = new String(buffer);
				// char c= sc.next().equals(".");
				// System.out.println(c);
				// System.out.println(convertToString);

				// dataOutput.flush();
				// for (int x=0; x<readInput.length();x++) {
				// byte[] buffer = readInput.charAt(x)getBytes();

				// dataOutput.write(buffer);
				if (readInput.equals(".")) {
					// System.out.println("hi");
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

			// byte[] serverStr = new byte[1024];
			/*
			 * String strOut=""; String strIn=""; while (!strOut.equals(".")) { strOut=
			 * inputStr.readLine(); dataOutput.writeUTF(strOut);
			 * //dataOutput.write(strOut.getBytes()); //dataOutput.flush();
			 * strIn=dataInput.readUTF(); System.out.println("Server: "+strIn);
			 */
			/*
			 * int strIn = dataInput.read(serverStr, 0, serverStr.length); while(strIn
			 * !=-1){ System.out.println("Server: "); buffer. }
			 * System.out.println("Server: "); dataOutput.write(readOutput);
			 * 
			 */

			// }

			dataInput.close();
			dataOutput.close();
			connection.close();
			// }
		} catch (IOException e) {
			System.err.println("Client Disconnected");

		}

	}

}