package edu.hfcc;

public abstract class ContactInfo implements Address
{
	private String name;
	
	private String lineOne;
	private String city;
	private String state;
	private int zipCode;
	
	public ContactInfo(String name, String lineOne, String city, String state, int zipCode)
	{
		setName(name);
		setLineOne(lineOne);
		setCity(city);
		setState(state);
		setZipCode(zipCode);
		
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setLineOne(String lineOne) {
		this.lineOne = lineOne;
	}

	public void setCity(String city) {
		this.city = city;
	}

	public void setState(String state) {
		this.state = state;
	}

	public void setZipCode(int zipCode) {
		this.zipCode = zipCode;
	}

	public String getName() {
		return name;
	}

	public String getLineOne() {
		return lineOne;
	}

	public String getCity() {
		return city;
	}

	public String getState() {
		return state;
	}

	public int getZipCode() {
		return zipCode;
	}

	public abstract boolean sendBirthdayCard();

	@Override
	public String toString() {
		return "ContactInfo [name=" + name + ", lineOne=" + lineOne + ", city=" + city + ", state=" + state
				+ ", zipCode=" + zipCode + "]\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	

}
