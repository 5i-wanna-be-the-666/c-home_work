package jdbc_6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketImpl;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

@SuppressWarnings("unused")
public class MyDB_duo {
	
	ServerSocket ss;
	Socket cltsocket;
	int clientNum=0;

	
		
		private static final String MYSQL_USERNAME = "yourStudentID";
		private static final String MYSQL_PASSWORD = "123456";
		
	
		private static final String MYSQL_DATABASE_SERVER = "mysql-user.muc";
		
		
		private static final String MYSQL_DATABASE_NAME = "myUniversity";
		
		private static Connection con;
		static String sqlInsert="insert into metropolises " +"VALUES(\"Rostov-on-Don\",\"Europe\",1052000)";
		static String str="select *from metropolises";
		static {
			try {
				Class.forName("com.mysql.cj.jdbc.Driver");
				String url = "jdbc:mysql://localhost:3306/myUniversity?useSSL=false&serverTimezone=UTC";
				con = DriverManager.getConnection(url, MYSQL_USERNAME, MYSQL_PASSWORD);
				System.out.println( "���������ɹ�!" );
				  System.out.println( "�������ݿ�ɹ�!" );
				  Statement st = con.createStatement();
			        System.out.println( "����Statement�ɹ�!" );
				  
			       
			} catch (SQLException e) {
				e.printStackTrace();
				System.err.println("student: Update the MySQL constants to correct values!");
			} catch (ClassNotFoundException e) {
				e.printStackTrace();
				System.err.println("student: Add the MySQL jar file to your build path!");
			}
		}
		
		public static Connection getConnection() {
			return con;
		}
		
		public static void close() {
			try {
				con.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		public ResultSet sh(ResultSet set) throws SQLException
		{
			 Statement st = con.createStatement();
			set=st.executeQuery( str );
			return set;
		}
		
		public void ins(String s1,String s2,String s3) throws SQLException
		{
			
			Statement st = con.createStatement();
			String sp="INSERT INTO metropolises VALUES("+"'"+s1+"'"+","+"'"+s2+"'"+","+"'"+s3+"'"+")";

		        System.out.println("��������ݳɹ�");
		}
		public MyDB_duo(int s) throws IOException
		{
			try {
       	  	 ss = new ServerSocket(6666); //����һ��Server Socket�����ڶ˿�6666 		
       	  	 System.out.println("Server is ready...");
		}catch(IOException e){
			System.err.println("Failed to creat Socket");
			System.exit(1);
		}
   	while(true){
   		try{
   			 cltsocket = ss.accept(); //������accept()��������Client������,����һ��Socket����
   		}catch (IOException e) {
   	    	System.err.println("Accept failed.");
   	    	System.exit(1);
   	    }
   		
		clientNum++;
   		//����������һ���̴߳���һ��Client������
   		new MultiServerThread(cltsocket, clientNum).start();  
   	}//end of while
		}
		
		public static void main(String[] args) throws IOException 
		
		{
			int port=6666;
			MyDB_duo k=new MyDB_duo(port);
			 
		}
}




		
