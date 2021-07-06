package java_homework_2_2;
import java_homework_2_2.DebitPayment.pT;
import java.util.Scanner;
@SuppressWarnings("unused")
public class MyMobilePayment extends DebitPayment{
	   
	   String number;
	   AliPay Ali;
	   WeChatPay WC;
	   JDPay JD;
	   UnionPay UP;
	   MyMobilePayment()
	   {
		   this.number="";
		   this.Ali=new AliPay();
		   this.WC=new WeChatPay();
		   this.JD=new JDPay();
		   this.UP=new UnionPay();
	   }
	   MyMobilePayment(String haoma,AliPay a,WeChatPay b,JDPay c,UnionPay d)
	   {
		   super(a.bankAcct,a.bankBalance,a.creditCardNum,a.creditLimit,a.payType);
		   this.number=haoma;
		   this.Ali=a;
		   this.WC=b;
		   this.JD=c;
		   this.UP=d;
	   }
	   public String toString()
	   {
		   
		   
		   return ("�绰����"+number+"\n"+super.toString()+"\n֧������Ϣ:"+this.Ali+"\n������Ϣ:"+this.JD+"\n΢����Ϣ:"+this.WC+"\n������Ϣ:"+this.UP);
	   }
	   void fuqian(DebitPayment a,double cost,pT payType)//ȷ��ʹ��ʲô��ʽ��Ǯ������ͳһ����ƽ̨�����ÿ����������
	   {
		   if(a==this.Ali)
		   {
			   this.bankBalance=this.Ali.bankBalance;
			   this.creditLimit=this.Ali.creditLimit;
			   
			   this.JD.bankBalance=this.bankBalance;
			   this.JD.creditLimit=this.creditLimit;
			   
			   this.WC.bankBalance=this.bankBalance;
			   this.WC.creditLimit=this.creditLimit;
			   
			   this.UP.bankBalance=this.bankBalance;
			   this.UP.creditLimit=this.creditLimit;
		   }
		   
		   if(a==this.JD)
		   {
			   this.JD.payMethod(cost, payType);
			   this.bankBalance=this.JD.bankBalance;
			   this.creditLimit=this.JD.creditLimit;

			   this.WC.bankBalance=this.bankBalance;
			   this.WC.creditLimit=this.creditLimit;
			   
			   this.UP.bankBalance=this.bankBalance;
			   this.UP.creditLimit=this.creditLimit;
			   
			   this.Ali.bankBalance=this.bankBalance;
			   this.Ali.creditLimit=this.creditLimit;
		   }
		   
		   if(a==this.UP)
		   {
			   this.UP.payMethod(cost, payType);
			   this.bankBalance=this.UP.bankBalance;
			   this.creditLimit=this.UP.creditLimit;
			   
			   
			   this.Ali.bankBalance=this.bankBalance;
			   this.Ali.creditLimit=this.creditLimit;
			   
			   this.JD.bankBalance=this.bankBalance;
			   this.JD.creditLimit=this.creditLimit;
			   
			   this.WC.bankBalance=this.bankBalance;
			   this.WC.creditLimit=this.creditLimit;
		   }
		   
		   if(a==this.WC)
		   {
			   this.WC.payMethod(cost, payType);
			   this.bankBalance=this.WC.bankBalance;
			   this.creditLimit=this.WC.creditLimit;
			   
			   this.UP.bankBalance=this.bankBalance;
			   this.UP.creditLimit=this.creditLimit;
			   
			   this.Ali.bankBalance=this.bankBalance;
			   this.Ali.creditLimit=this.creditLimit;
			   
			   this.JD.bankBalance=this.bankBalance;
			   this.JD.creditLimit=this.creditLimit;
		   }
	   }
	   
	   
       public static void main(String[] args)
       {
    	   AliPay a=new AliPay("3355",9568,"7756",100000,pT.bankfirst, "7799", 500);//֧�������������п�����
    	   WeChatPay b=new WeChatPay("3355",9568,"7756",100000,pT.bank, "9977", 600);//΢�����õ���ֻ�����п�
    	   JDPay c=new JDPay("3355",9568,"7756",100000,pT.credit, "8597", 700);//����ֻ�����ÿ�
    	   UnionPay d=new UnionPay("3355",9568,"7756",100000,pT.creditfirst, "3598", 800);//���������ÿ�����
    	   
    	   // ������㽨�����ĸ�����
    	   MyMobilePayment me=new  MyMobilePayment("19957392890",a,b,c,d);//�ֻ�����
    	   
    	   System.out.println("����֧�������");
    	   me.fuqian(c, 9000,c.payType);
    	   System.out.println("֧����֧�������");
    	   me.fuqian(a,800,pT.credit);
    	   me.fuqian(b,900,b.payType);
    	   System.out.println(me.toString());
    	  
       }
}
