package edu.hfcc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

//import edu.hfcc.io.PathCreator;

public class getInfoFromFile 
{
//	public PathReader info;
	
	private static final String DELIMTER = ",";
	List<ContactInfo> returnedToApp = new ArrayList<>();

	public List<ContactInfo> createList(String fileName) {
		
		
	PathCreator pathCreator = new PathCreator();
//	String fileName = pathCreator.getPathInfo().toString();
	Path path = pathCreator.getPathInfo(fileName);
		
	//	Path readFile = new PathCreator().getPathInfo(readFromFile, "input");
		
		if(!Files.exists(path))
		{
			System.out.println("Files does not exist");
			System.exit(0);
		}
		
		InputStream input = null;
	//	List<String> items = new ArrayList();
		try {
			input = Files.newInputStream(path);
			BufferedReader reader = new BufferedReader(new InputStreamReader(input));
			try {
				String line = reader.readLine();
				while ((boolean) (line != null)){
					createContact(line);
					line = reader.readLine();
				}
			} finally {
				reader.close();
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				input.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return returnedToApp;
	}
	
	private void createContact(String line)
	{
		Object [] objectArray = line.split(DELIMTER);
		System.out.println(objectArray[1]);
		switch((String)objectArray[0])
		{
		case"Friend":
			ContactInfo friendContact = new Friend((String)objectArray[1], (String)objectArray[2],
					(String)objectArray[3], (String)objectArray[4],
					Integer.parseInt((String)objectArray[5]));
				returnedToApp.add(friendContact);
				break;
		case"Family":
			ContactInfo familyContact = new Family((String)objectArray[1], (String)objectArray[2],
					(String)objectArray[3], (String)objectArray[4],
					Integer.parseInt((String)objectArray[5]));
			returnedToApp.add(familyContact);
			break;
		case"Business":
			ContactInfo businessContact = new Business((String)objectArray[1], (String)objectArray[2],
					(String)objectArray[3], (String)objectArray[4],
					Integer.parseInt((String)objectArray[5]));
			returnedToApp.add(businessContact);
			break;
		
		}
		
		
		
		
	}

}


