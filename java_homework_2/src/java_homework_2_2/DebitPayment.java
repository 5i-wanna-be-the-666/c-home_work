package java_homework_2_2;

import java.util.Scanner;

import java_homework_2_2.DebitPayment.pT;
import java.util.Scanner;
@SuppressWarnings("unused")
public class DebitPayment {
	public enum pT{  
		 bank,credit,bankfirst,creditfirst;
	 }//��ö�����Ͷ���
	
	String bankAcct;        //�����˺�
	 double bankBalance;      //�������
	 String creditCardNum;    //���ÿ���
	 double creditLimit;      //���ÿ����
	 pT payType;          //֧������
	 
	 public DebitPayment()
	 {
		 this.bankAcct="";
		 this.bankBalance=0;
		 this.creditCardNum="";
		 this.creditLimit=50;
		 this.payType=pT.bankfirst;
		 
	 }
	 public DebitPayment(String a,double b,String c,double d,pT e)
	 {
		 this.bankAcct=a;
		 this.bankBalance=b;
		 this.creditCardNum=c;
		 this.creditLimit=d;
		 this.payType=e;
		 
	 }
	 public void gaifu(pT c)//�ı�֧�����͵ĺ���
	 {
		 this.payType=c;
	 }
	 public String toString()
	 {
		 return ("������Ϣ"+this.bankAcct+"  "+this.bankBalance+"���ÿ���Ϣ"+this.creditCardNum+"  "+this.creditLimit);
	 }
	 double payMethod(double cost,pT payType)//�Ҳ��������������Ҫ����������д
	 //Ҳ���ǣ��Ҿ��ò�����һ��ƽ̨������֧��������֧����ʽ�е�ÿһ��
	 //��Ϊ������һ�������֧���������������֣��Ҳ�û����֧������ӵ��������΢����ӵ��΢��Ǯ��֮���
	 //Ҳ���������ַ�������ͨ�õģ�����ʹ�����Լ��������������ÿ����ȥ֧��
	 //�Ҳ�������������д���������Լ���֧������������������΢��������һ����Ǯ�˻�������д,����֧����������������
	 {
		 //0 ��һ�ַ�����ʹ�����п����ȸ��ѣ���Ҳ��Ĭ�ϵ�֧������ 
		 if(payType==pT.bankfirst)
		 {
			 if(this.bankBalance>=cost)
			 {
				 this.bankBalance-=cost;
				 System.out.println("֧���ɹ�   �������"+this.bankBalance);
	    		 return 1;
			 }
			 else
			 {
				 System.out.println("�������㣬����ʹ�����ÿ�֧�����Ƿ�ȷ����");
				 System.out.println("1��ȷ��  "+"2��ȡ��");
				 int cloose=2;
				 Scanner s=new Scanner(System.in);
				 if(s.hasNextInt())
				 {
					 cloose=s.nextInt();
				 }
				 while(cloose!=1&&cloose!=2)
				 {
					 System.out.println("������������������");
					 cloose=s.nextInt();
				 }
			     s.close();
			     
			     if(cloose==1)
			     {

					
					 
			    	 if(this.creditLimit+this.bankBalance<cost)
			    	 {
			    		 System.out.println("֧��ʧ��");
			    		 return 0.0;
			    	 }
			    	 
			    	 else
			    	 {
			    		 cost-=this.bankBalance;//�������е�����������֧��
						 this.bankBalance=0;
			    		 this.creditLimit-=cost;//�������ÿ�֧��
			    		 System.out.println("֧���ɹ�   ���ÿ�ʣ����"+this.creditLimit);
			    		 return 1;
			    	 }
			     }
			 
				
				 
				 
			 }
		 }
		//��һ�ַ�����ʹ�����п����ȸ��ѣ���Ҳ��Ĭ�ϵ�֧������ 
		 
		 
		 
		 
		 
		 
		//1 �ڶ��ַ�����ʹ�����ÿ�����֧��
		 if(payType==pT.creditfirst)
		 {
			 if(this.creditLimit>=cost)
			 {
				 this.creditLimit-=cost;
				 System.out.println("֧���ɹ�   ���ÿ�ʣ����"+this.creditLimit);
	    		 return 1;
			 }
			 else
			 {
				 System.out.println("���ÿ����㣬����ʹ���������֧�����Ƿ�ȷ����");
				 System.out.println("1��ȷ��  "+"2��ȡ��");
				 int cloose=2;
				 Scanner s=new Scanner(System.in);
				 if(s.hasNextInt())
				 {
					 cloose=s.nextInt();
				 }
				 while(cloose!=1&&cloose!=2)
				 {
					 System.out.println("������������������");
					 cloose=s.nextInt();
				 }
			     s.close();
			     
			     if(cloose==1)
			     {
			    	 
			    	 if(this.bankBalance+this.creditLimit<cost)
			    	 {
			    		 System.out.println("֧��ʧ��");
			    		 return 0.0;
			    	 }
			    	 
			    	 else
			    	 {
			    		 
			    		cost-=this.creditLimit;//�������ÿ�֧��
			    		 this.creditLimit=0;
			    		 this.bankBalance-=cost;//�����������֧��
			    		 System.out.println("֧���ɹ�   �������"+this.bankBalance);
			    		 return 1;
			    		
			    	 }
			     }
			     
			     if(cloose==2)
			     {
			    	 System.out.println("֧��ʧ��");
		    		 return 0.0;
			     }
			    	 
			 
				 
				 
			 }
		 }
		 //�ڶ��ַ�����ʹ�����ÿ�����֧��
		 
		 //2 �����ַ�����ʹ���������֧��
		 if(payType==pT.bank)
		 {
			 if(cost>this.bankBalance)
			 {
				 System.out.println("֧��ʧ��");
				 return 0;
			 }
			 
			 this.bankBalance-=cost;//���������֧��
			 System.out.println("֧���ɹ�   �������"+this.bankBalance);
    		 return 1;
    		
		 }
		 
		//�����ַ�����ʹ���������֧��
		 
		 
		 
		 //3�����ַ�����ʹ�����ÿ����֧��
		 if(payType==pT.credit)
		 {
			 if(cost>this.creditLimit)
			 {
				 System.out.println("֧��ʧ��");
				 return 0;
			 }
			 
			 this.creditLimit-=cost;//�����ÿ����֧��
    		 System.out.println("֧���ɹ�   ���ÿ�ʣ����"+this.creditLimit);
    		 return 1;
    		
		 }
		 //�����ַ�����ʹ�����ÿ����֧��
		 return 0.0; 
				
	 }
	
		
	
	
	
}
