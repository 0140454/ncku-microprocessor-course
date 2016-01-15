
#include "io430.h"
#include "stdio.h"
#include "aes.h"

char data[16];
int received_bytes;

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  // AES Test Block
  /*uint8_t key[] = {
    0x2b, 0x7e, 0x15, 0x16,
    0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88,
    0x09, 0xcf, 0x4f, 0x3c };
  
  uint8_t data[] = "der58t4r5fr254trg24er5r5r78965@!";

  EncryptCFB(data, 2, key, key);
  
  for (int i = 0; i < 32; ++i)
       printf("%x ", data[i]);
  puts("");
  
  DecryptCFB(data, 2, key, key);
  
  printf("%s", data);*/

  // Setup UART
  P4SEL = BIT4 + BIT5;          // Use P4.4 and P4.5 for UART

  UCA1CTL1 |= UCSWRST;          // Start to setup UART
  UCA1CTL1 |= UCSSEL_2;
  
  UCA1BR1 = 0;
  UCA1BR0 = 109;
  
  UCA1MCTL = UCBRS_2 + UCBRF_0;

  UCA1CTL1 &= ~UCSWRST;         // Finish UART setup
  UCA1IE |= UCRXIE;
  
  // Low Power Mode
  __bis_SR_register(LPM3_bits + GIE);
  __no_operation();

  return 0;
}

#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
  switch(__even_in_range(UCA1IV, 4))
  {
  case 0:
    break;
  case 2:                               // TX -> RXed character
    while(!(UCA1IFG & UCTXIFG))
      ;
    data[received_bytes++] = UCA1RXBUF;
    if (received_bytes == 16) {
      // AES
    }
    break;
  case 4:                               // Vector 4 - TXIFG
    break; 
  default: 
    break;  
  }
}