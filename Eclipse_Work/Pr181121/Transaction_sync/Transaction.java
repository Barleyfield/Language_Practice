package Transaction_sync;

public class Transaction implements Runnable {

	private Account acc;
	
	public Transaction(Account account) {
		acc = account;
	}
	
	public void deposit(int amount)
	{
		acc.deposit(amount); 
		pretendProcessing(0);
		// �����ϴ� �ð��� ������ ����
		// �� ��ü�� ����ȭ�� ��� ����

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
		try {
			thread1.join();
		} catch (InterruptedException e) {
			System.out.println("����ڿ� ���� �ߴܵ�");
		}
		
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
	// synchronized�� ���
	// Account ��ü�� ���¸� �ٲٴ� deposit�� withdraw��
	// ����ȭ �޼ҵ�� ����Ǿ���.
	public synchronized void deposit(int amount)
	{
		balance += amount;
	}
	public synchronized void withdraw(int amount)
	{
		balance -= amount;
	}
	public int balance()
	{
		return balance;
	}
}
