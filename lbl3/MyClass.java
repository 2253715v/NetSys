import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.Queue;

/**
 * @author 2253715v
 *
 */
public class MyClass {

	public static void main(String[] args) {
		if (args.length == 1) {
			// The name of the file to open.
			String fileName = args[0];

			// This will reference one line at a time
			String line = null;
			StringBuilder stringBuilder = new StringBuilder();
			try {
				// FileReader reads text files in the default encoding.
				FileReader fileReader = new FileReader(fileName);

				// Always wrap FileReader in BufferedReader.
				BufferedReader bufferedReader = new BufferedReader(fileReader);
				Queue<String> nodeQ = new LinkedList<String>();
				String endNode = "";
				while ((line = bufferedReader.readLine()) != null) {
					// skip the last line
					System.out.println("line: " + line);
					line = line.trim();
					if (!line.equals("")) {
						if (line.startsWith("traceroute")) {
							endNode = line.split("\\s")[2];
						} else {
							String lineParts[] = line.split("\\s\\s");
							if (lineParts.length >=2 ) {
								if (!lineParts[1].equals("*"))
									nodeQ.add(lineParts[1]);
							}
						}
					}
				}

				// Always close files.
				bufferedReader.close();
				//Process
				while (!nodeQ.isEmpty()) {
					if(nodeQ.peek() != null && !nodeQ.peek().toString().equals("null")) 
					{
					stringBuilder.append('"' + nodeQ.poll() + '"' + " -- " + '"' + nodeQ.peek() + '"' );
					stringBuilder.append(System.getProperty("line.separator"));
					}
				}
				//Write

				//Get the file reference
				Path path = Paths.get("processed_" + fileName);

				//Use try-with-resource to get auto-closeable writer instance
				try (BufferedWriter writer = Files.newBufferedWriter(path)) {
					writer.write(stringBuilder.toString());
				}

			} catch (FileNotFoundException ex) {
				System.out.println("Unable to open file '" + fileName + "'");
			} catch (IOException ex) {
				System.out.println("Error reading file '" + fileName + "'");
				// Or we could just do this:
				ex.printStackTrace();
			}

		}
	}

}
