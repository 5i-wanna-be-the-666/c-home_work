package jdbc_3;

class ren implements Runnable{
	boolean flag;
	static zhanghu o1;//��������Ǿ�̬��������������Ͳ�����ͬһ�������ϼ�����
	static zhanghu o2;	
	static jiaoyi tb;
	@SuppressWarnings("static-access")
	public ren(boolean flag,zhanghu daoyan,zhanghu yanyuan,jiaoyi kp)
	{
		this.o1=daoyan;
		this.o2=yanyuan;
		this.flag=flag;
		this.tb=kp;
	}
 
	public void run() {
		if(flag){
			
			synchronized(o1){
				
				
				
					try{
						Thread.sleep(100);
						System.out.println("I am t1,get o1's lock");
						
						o1.flag=true;
						
						
					}
					catch(InterruptedException e){
						e.printStackTrace();
					}
					
				while(o2.flag)
					try {
						o1.wait();
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				
				
					synchronized(o2){//Ҫ����o1�ٽ����ڣ���ΪҪ����o1����������o2����
						System.out.println("I am t1,get o2's lock");
						System.out.println("I am not dead lock!");
						tb.zhuan_zhang(o1,o2);
						System.out.println(o1.toString());
						System.out.println(o2.toString());
						
						if(o2.flag)
						o2.notify();
					}
				
			
				
			}
			
		}
		else{
		
			synchronized(o2){
				
				
					try{
						Thread.sleep(100);
						System.out.println("I am t2,get o2's lock");
					    o2.flag=true;
						
						
					}
					catch(InterruptedException e){
						e.printStackTrace();
					}
					
					
					while(o1.flag)
						try {
							o2.wait();
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					
					
					synchronized(o1){//�˴����ƣ�����o2����������o1����
						System.out.println("I am t2,get o1's lock");
						System.out.println("I am not dead lock, too.");
						tb.zhuan_zhang(o2, o1);
						System.out.println(o1.toString());
						System.out.println(o2.toString());
						
						if(o1.flag)//
						o1.notify();
					}
					
					
			}
			
		}
	}
	
}

