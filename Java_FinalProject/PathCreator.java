package edu.hfcc;

import java.nio.file.Path;
import java.nio.file.Paths;

public class PathCreator
{
	public Path getPathInfo(String fileName) {
		
	//	fileName = "contact_input.txt";
	///	Path overAllPath = Paths.get(fileName).toAbsolutePath();
	//	Path parentPath = overAllPath.getParent();
		String projectPath = Paths.get(fileName).toAbsolutePath().getParent().toString();
		String filePath = "/src/main/resources/input/";

		return Paths.get(projectPath + filePath + fileName);	
	}
	
	public void grabInfo()
	{
		
		
	}
}
