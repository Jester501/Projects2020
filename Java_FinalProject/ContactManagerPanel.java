package edu.hfcc;

import java.awt.FlowLayout;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class ContactManagerPanel extends JFrame{

	
	private List<ContactInfo> familyContacts = new ArrayList<ContactInfo>();
	private List<ContactInfo> friendContacts = new ArrayList<ContactInfo>();
	private List<ContactInfo> businessContacts = new ArrayList<ContactInfo>();
	
	private List<JCheckBox> familyJCheckBoxes = new ArrayList<JCheckBox>();
	private List<JCheckBox> friendJCheckBoxes = new ArrayList<JCheckBox>();
	private List<JCheckBox> businessJCheckBoxes = new ArrayList<JCheckBox>();
	
	public ContactManagerPanel(String title) {
		// TODO Auto-generated constructor stub
		super(title);
	//	rf = new getInfoFromFile();
		setSize(500, 400);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
	//	add(new JLabel("   Contact Manager                                                                                 "));
	//	JPanel();
		createContactsToSort();
		createCheckBoxes();
	//	createCheckBox1();
		//test
	
	}
	
	public void createContactsToSort()
	{
		 getInfoFromFile fileReader = new getInfoFromFile();
		List<ContactInfo> returnedToApp = fileReader.createList("contact_input.txt");
		sortContacts(returnedToApp);
	}
	
	private void sortContacts(List<ContactInfo> returnedToApp)
	{
		for(ContactInfo contact : returnedToApp)
			if(contact instanceof Family)
			{
				familyContacts.add(contact);
			}
			else if(contact instanceof Friend)
			{
				friendContacts.add(contact);
			}
			else if(contact instanceof Business)
			{
				businessContacts.add(contact);
			}
	}//test2 i think, I have changed this line, im also listening to camel phat and I am thinking of the possibly of improving my github account
	
	private void createCheckBoxes()
	{
		createFamilyJCheckBoxes();
		createFriendsJCheckBoxes();
		createBusinessJCheckBoxes();
	}
	
	private void createFamilyJCheckBoxes()
	{
		add(new JLabel("Family: "));
		for(ContactInfo contact : familyContacts)
		{
			JCheckBox checkBox = new JCheckBox(contact.getName(), false);
			familyJCheckBoxes.add(checkBox);
			add(checkBox);
		}
	}
	
	private void createFriendsJCheckBoxes()
	{
		{
			add(new JLabel("Friends: "));
			for(ContactInfo contact : friendContacts)
			{
				JCheckBox checkBox = new JCheckBox(contact.getName(), false);
				friendJCheckBoxes.add(checkBox);
				add(checkBox);
			}
		}
	}
	
	private void createBusinessJCheckBoxes()
	{
		{
			add(new JLabel("Business: "));
			for(ContactInfo contact : businessContacts)
			{
				JCheckBox checkBox = new JCheckBox(contact.getName(), false);
				businessJCheckBoxes.add(checkBox);
				add(checkBox);
			}
		}
	}
	
	/* public void createCheckBox1()
	{
		List<String> items = this.rf.createList("contact_input.txt");//this.getInfoFromFile.createList("contact_input.txt");
		
		//JPanel jp = new JPanel();
	//	jp.add(new JLabel("Family     "));
		JPanel();
		if(items.indexOf(o))
		for(String item : items) {
			JCheckBox itemCheckBox = new JCheckBox(item);
			add(itemCheckBox);
			itemCheckBox.addItemListener(this);	
		}
	}
	
	public void JPanel()
	{
		JPanel jp = new JPanel();
		jp.add(new JLabel("Family     "));
	/*	JPanel fp = new JPanel();
		JPanel bp = new JPanel();
		
		
		add(new JLabel("   Contact Manager                                                                                 "));
		
		jp.add(new JLabel("                   "));
		jp.add(new JLabel("Family     "));
		jp.add(new JCheckBox("Lula Gains"));
		jp.add(new JCheckBox("Tony Starks"));
		jp.add(new JLabel("                                       "));
		
		fp.add(new JLabel("Friend"));
		fp.add(new JCheckBox("Sally Jons"));
		fp.add(new JCheckBox("Doug Meh"));
		fp.add(new JCheckBox("Kelly Sikes")); //replace hardcode with file from outputstream
		
		bp.add(new JLabel("Bussiness"));
		bp.add(new JCheckBox("Chase Webber"));
		
		add(jp);
		add(fp);
		add(bp);
		
	}
	
	
	@Override
	public void itemStateChanged(ItemEvent e) {
		// TODO Auto-generated method stub
		System.out.println(((JCheckBox)e.getItem()).getText());
	}

	/*@Override
	public String[] manageFriends() {
		// TODO Auto-generated method stub
		return null;
	}*/
	
	

}
