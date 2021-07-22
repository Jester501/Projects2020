package edu.hfcc;

public class Business extends ContactInfo {
	
	public Business(String name, String lineOne, String city, String state, int zipCode)
	{
		super(name,lineOne,city,state, zipCode);	
		
	}


	@Override
	public boolean sendBirthdayCard() {
		// TODO Auto-generated method stub
		return false;
	}
	
}
