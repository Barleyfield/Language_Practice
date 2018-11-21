package Transaction;

public class Transaction implements Runnable {

	private Account acc;
	
	public Transaction(Account account) {
		acc = account;
	}
	
	public void deposit(int amount)
	{
		acc.deposit(amount); 
		pretendProcessing(1000);
		// ������ �ݾ��� �Ա��ϰ� 1�ʰ� ������.
		// �����ϴ� 1�ʴ� ó�� �ð��� �䳻
	}
	
	protected void pretendProcessing(int delayInMillis) {
		try {
			Thread.sleep(delayInMillis);
		} catch (InterruptedException e) {
			System.out.println("����ڿ� ���� �ߴܵ�");
		}
		// Thread.sleep() �޼ҵ�� �ߴ� ���ܸ� �߻���Ű�Ƿ�
		// try-catch ������� ���μ� ó��
	}
	
	public void run() {
		deposit(10000);
		// 10000�� �Ա�
	}
	
	public static void main(String[] args) {
		Account account = new Account();
		System.out.printf("���� �� �ܾ� = %d\n", account.balance());
		Transaction tr = new Transaction(account);
		Thread thread1 = new Thread(tr);
		thread1.start();
		tr.run();
		// ���ο� ������ thread1�� ����. 10000�� �Ա�
		// ���� ���� tr.run()�� �����Ͽ� ����
		System.out.printf("���� �� �ܾ� = %d\n", account.balance());
	}

}

class Account
{
	private int balance;
	public Account()
	{
		balance = 0;
	}
	public void deposit(int amount)
	{
		balance += amount;
	}
	public void withdraw(int amount)
	{
		balance -= amount;
	}
	public int balance()
	{
		return balance;
	}
}