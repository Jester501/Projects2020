package edu.hfcc;

public class Friend extends ContactInfo{
	
	public Friend(String name, String lineOne, String city, String state, int zipCode)
	{
		super(name, lineOne, city, state, zipCode);
		
	}

	@Override
	public boolean sendBirthdayCard() {
		// TODO Auto-generated method stub
		return true;
	}

}
