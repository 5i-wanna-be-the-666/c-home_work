package jdbc_5;



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
					
					//System.out.println("�յ��������ת��");
				}
				else {
					k1.flag=false;//ת�����
					k2.shou=false;
					k1.dai_zhuan=0;
					// System.out.println("����,ת��ʧ��");
					 return;
				}
			
				 k2.yu_e+=pingtai;
				 pingtai=0;
				 k1.flag=false;//ת�����
				 k2.shou=false;
				 k1.trans+=1;
				 k2.trans+=1;
				// System.out.println("ת��ɹ�");
				 
			 
			 
			 
		 
	 }
}
