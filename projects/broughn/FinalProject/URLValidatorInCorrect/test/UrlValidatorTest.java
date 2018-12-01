

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }
   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   private String[] scheme = new String[5];
      scheme[0] = "www.google.com";
      scheme[1] = "http://www.google.com:80/test1";
      scheme[2] = "3ht://www.google.com";
      scheme[3] = "http://go.1aa";
      scheme[4] = "http://www.google.com:-1";
      UrlValidatorTest testUrl = new UrlValidatorTest();
      for (int i = 0; i < 5; i++) {
         UrlValidatorTest testUrl = new UrlValidatorTest(scheme[i]);
         testUrl.testIsValid();
      }

   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing
      private String[] scheme = new String[5];
      scheme[0] = "http://";
      scheme[1] = "ftp://";
      scheme[2] = "";
      scheme[3] = "3ht://";
      scheme[4] = "http:"

      private String[] auth = new String[5];
      auth[0] = "www.google.com";
      auth[1] = "go.com";
      auth[2] = "255.com";
      auth[3] = "go.a";
      auth[4] = "go.au";

      private String[] testArray = new String[6];
      testArray[0] = scheme[0]+auth[0];
      testArray[1] = scheme[3]+auth[1];
      testArray[2] = scheme[0]+auth[3];
      testArray[3] = scheme[1]+auth[2];
      testArray[4] = scheme[2]+auth[0];
      testArray[5] = scheme[4]+auth[4];

      for (int i = 0; i < 6; i++) {
         UrlValidatorTest testUrl = new UrlValidatorTest(testArray[i]);
         // testUrl.setUp();
         testUrl.testIsValid();
      }
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing
      String schauth = "http://www.google.com";

      private String[] port = new String[4];
      port[0] = ":0";
      port[1] = ":80";
      port[2] = ":-1";
      port[3] = "";


      private String[] path = new String[3];
      path[0] = "/test1";
      path[1] = "/..";
      path[2] = "";

      private String[] query = new String[2];
      query[0] = "?action=view";
      query[1] = "";

      
      private String[] testArray = new String[6];
      testArray[0] = port[1]+query[2]+query[1];
      testArray[1] = port[2]+query[2]+query[1];
      testArray[2] = port[0]+query[0]+query[1];
      testArray[3] = port[0]+query[1]+query[1];
      testArray[4] = port[2]+query[1]+query[1];
      testArray[5] = port[1]+query[0]+query[0];

      for (int i = 0; i < 6; i++) {
         UrlValidatorTest testUrl = new UrlValidatorTest(testArray[i]);
         // testUrl.setUp();
         testUrl.testIsValid();
      }
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
      UrlValidator urlValid = new UrlValidator(null, null, allowAllSchemes);
      boolean result = urlValid.isValid(testName);
      assertTrue(result);
   }
   

   public static void main(String[] argv){
            UrlValidatorTest functionA = new UrlValidatorTest("url test"){
            functionA.testManualTest();
            functionA.testYourFirstPartition();
            funcitonA.testYourSecondPartition();
            
       }
   }
}
