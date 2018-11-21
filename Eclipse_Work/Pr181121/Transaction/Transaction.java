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
		// 정해진 금액을 입금하고 1초간 정지함.
		// 정지하는 1초는 처리 시간을 흉내
	}
	
	protected void pretendProcessing(int delayInMillis) {
		try {
			Thread.sleep(delayInMillis);
		} catch (InterruptedException e) {
			System.out.println("사용자에 의해 중단됨");
		}
		// Thread.sleep() 메소드는 중단 예외를 발생시키므로
		// try-catch 블록으로 감싸서 처리
	}
	
	public void run() {
		deposit(10000);
		// 10000원 입금
	}
	
	public static void main(String[] args) {
		Account account = new Account();
		System.out.printf("예금 전 잔액 = %d\n", account.balance());
		Transaction tr = new Transaction(account);
		Thread thread1 = new Thread(tr);
		thread1.start();
		tr.run();
		// 새로운 스레드 thread1을 시작. 10000원 입금
		// 같은 업무 tr.run()을 병행하여 수행
		System.out.printf("예금 후 잔액 = %d\n", account.balance());
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