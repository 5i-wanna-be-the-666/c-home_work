package jdbc_5;



public class zhanghu extends Thread{
	
	int hao;
	int yu_e;
	int dai_cun;
	int dai_zhuan;
	int trans;
	boolean iswaitting;//��־���Ƿ����ڵȴ�
	boolean flag;//��־���Ƿ�����ת��
	boolean shou;//��־���Ƿ�������Ǯ
	
	
	
	public zhanghu(int n,int num)
	{
		
		this.yu_e=n;
		this.hao=num;
		
		this.dai_cun=0;
		this.dai_zhuan=0;
		this.trans=0;
		
		this.flag=false;
		this.iswaitting=false;
		this.shou=false;
	}
	
	public  void cun(int n)
	{
		
		this.dai_cun=n;
	}
	public void set_zhuan(int n)
	{
		this.dai_zhuan=n;
	}
	public String toString()
	{
		return ("�˻����"+this.hao+"�˻����:"+this.yu_e+","+"������:"+this.dai_cun+","+"��ת���:"+this.dai_zhuan+"ת�˴���"+this.trans);
		
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		
			if(this.dai_cun!=0)
			{
				this.yu_e+=this.dai_cun;
				
				System.out.println("��Ǯ�ɹ�,"+this.dai_cun);
				this.dai_cun=0;
			}
		
			
		
	}

}

