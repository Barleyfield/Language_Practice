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
		// 정지하는 시간이 없도록 수정
		// 이 자체는 동기화와 상관 없음

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
		try {
			thread1.join();
		} catch (InterruptedException e) {
			System.out.println("사용자에 의해 중단됨");
		}
		
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
	// synchronized를 사용
	// Account 객체의 상태를 바꾸는 deposit가 withdraw는
	// 동기화 메소드로 선언되었음.
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
