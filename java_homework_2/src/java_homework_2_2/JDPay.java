package java_homework_2_2;

import java_homework_2_2.DebitPayment.pT;
import java.util.Scanner;
@SuppressWarnings("unused")

public class JDPay extends DebitPayment {
	String JDAcct;
	double JDbaitiao;
	
	JDPay()
	{
		super();
	}
	
	JDPay(String a,double b,String c,double d,pT e,String f,double o)
	{
		super(a,b,c,d,e);
		this.JDAcct=f;
		this.JDbaitiao=o;
	}
	public String toString()
	 {
		 return ("������Ϣ"+this.JDAcct+"  "+this.JDbaitiao+"������Ϣ"+this.bankAcct+"  "+this.bankBalance+"���ÿ���Ϣ"+this.creditCardNum+"  "+this.creditLimit);
	 }
	double payMethod(double cost,pT payType)
	 {
		 @SuppressWarnings("resource")
		Scanner s=new Scanner(System.in);
		 int n=0;
		 System.out.println("������ʹ�þ������֧����Ȼ����ָ���ķ���֧��");
		 System.out.println("1��ȷ��   2:����Ҫ����Ҫ��ѡ��ķ�ʽ����֧��");
		 while(n!=1&&n!=2)
		 {
			 System.out.println("������:");
			 n=s.nextInt();
			 if(n!=1&&n!=2)
				 System.out.println("�������"); 
		 }
		 
		 if(n==1)//ȷ����Ҫ
		 {
			 if(this.JDbaitiao>=cost)
			 {
				 System.out.println("֧���ɹ�");
				 this.JDbaitiao-=cost;
				 System.out.println("�������Ϊ:"+this.JDbaitiao);
				 return 1;
			 }
			 else
			 {
				 cost-=this.JDbaitiao;//����ʹ�þ���������֧��
				 this.JDbaitiao=0;
				 super.payMethod(cost,payType);//�ٰ�ָ������֧��
			 }
		 }
		 
		 if(n==2)//����Ҫ
		 {
			 super.payMethod(cost, payType);
		 }
		 return 0;
	 }

}
