package jdbc_3;

public class zhanghu implements Runnable{
	String name;
	int hao;
	int yu_e;
	int dai_cun;
	int dai_zhuan;
	int trans;
	boolean flag;//��־���Ƿ�����ת��
	public zhanghu(String s,int n)
	{
		this.name=s;
		this.yu_e=n;
		this.dai_cun=0;
		this.dai_zhuan=0;
		this.trans=0;
		
		this.flag=false;
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
		return ("�˻�����"+this.name+"�˻����:"+this.yu_e+","+"������:"+this.dai_cun+","+"��ת���:"+this.dai_zhuan);
		
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
