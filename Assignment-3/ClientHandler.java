import java.io.*;
import java.net.*;
public class ClientHandler extends Thread {
    private Socket clientSocket;
	/*public static void main(String[] args) {
		// TODO Auto-generated method stub

	}*/
	ClientHandler(Socket clientSocket){
		this.clientSocket = clientSocket;
		
	}
	public void run() {
		try {
		InputStream dataInput = clientSocket.getInputStream();
		OutputStream dataOutput = clientSocket.getOutputStream();
		
		
		while (true) {
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
		clientSocket.close();
		
		}
		catch(IOException e) {
			
		}
	}

}
