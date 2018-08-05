package ch5;

interface PhoneInterface
{
	int BUTTONS = 20;
	void sendCall();
	void receiveCall();
}

interface MobilePhoneInterface extends PhoneInterface
{
	void sendSMS();
	void receiveSMS();
}


class FeaturePhone implements MobilePhoneInterface
{
	public void sendCall()
	{
		System.out.println("Send Call");
	}
	public void receiveCall()
	{
		System.out.println("Receive Call");
	}
	
	public void sendSMS()
	{
		System.out.println("Send SMS");
	}
	
	public void receiveSMS()
	{
		System.out.println("Receive SMS");
	}
}

public class Ch5_another_interface {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FeaturePhone f = new FeaturePhone();
		f.sendCall();

	}

}
