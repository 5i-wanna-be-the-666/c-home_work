package jdbc_3;

public class jiaoyi {
	
	int pingtai;
	public jiaoyi()
	{
		this.pingtai=0;
	}
	 
	 
	
	 public void zhuan_zhang(zhanghu k1,zhanghu k2)
	 {
		 
			 if(k1.yu_e>=k1.dai_zhuan)
				{
				 k1.flag=true;//����Ϊ����ת��״̬
					k1.yu_e-=k1.dai_zhuan;
					pingtai=k1.dai_zhuan;
					k1.dai_zhuan=0;
					
					System.out.println("�յ��������ת��");
				}
				else {
					 System.out.println("����");
				}
			
				 k2.yu_e+=pingtai;
				 pingtai=0;
				 k1.flag=false;//ת�����
				 System.out.println("ת��ɹ�");
				 
			 
			 
			 
		 
	 }

}
