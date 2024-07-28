
#include <PA9.h>

#include <nds.h>

#define EXMEMCNT ((uint16*)0x04000204) // gère différentes propriétés du port GBA
#define V_SRAM ((volatile unsigned char*)0x0A000000) // SRAM

//-------------------------------------------------------
//  DSIO_CMD : Base de la communication avec DSIO
//  Argument = Commande à envoyer , Retourne Donnée recue
//-------------------------------------------------------

u8 DSIO_CMD(u8 addr)
{
	// Don't write to the slot 2 space in a DSi. It will cause an exception
	if (isDSiMode())
		return 0;

	u8 i;
	for(i=0;i<30;i++)
	V_SRAM[addr];
   return V_SRAM[addr];
}

//--------------------------------------------------------
// DSIO_Rumble_On : met en route le vibreur
//--------------------------------------------------------

void DSIO_Rumble_On(void)
{
 	DSIO_CMD(0x01);
}

//--------------------------------------------------------
// DSIO_Rumble_Off : éteind le vibreur
//--------------------------------------------------------

void DSIO_Rumble_Off(void)
{
  	DSIO_CMD(0x02);
}

//--------------------------------------------------------
// DSIO_Light: Permet d'obtenir valeur de luminosité du capteur
// Attention il faut un certain temps pour obtenir la donnée
//--------------------------------------------------------

u8 DSIO_Light()
{
	u8 temp;
 	DSIO_CMD(0x03);
	swiWaitForVBlank();
 	temp=DSIO_CMD(0x04);
 	return temp;

}
//--------------------------------------------------------
// DSIO_Connect: Détecte et Initialise l'interface
// Retourne 1 si Ok sinon 0
//--------------------------------------------------------

bool DSIO_Connect()
{
  if(DSIO_CMD(0x54)==0x00)  //R
  {
  	     return 1;
  }
  return 0;
}

//-----------------------------------------------------------
// DSIO_Init: Arm9 gère port GBA, horloge GBA 16Mhz et purge
//            pour éviter une commande "parasite"
//-----------------------------------------------------------

void DSIO_Init(void)
{
   EXMEMCNT[0]=0x607B;
   DSIO_CMD(0x00);
}

//------------------------------------------------------------
//DSIO_BP: Etat du Bouton Poussoir ? 1 si Appuyé et 0 si relaché
//------------------------------------------------------------

u8 DSIO_BP(void)
{
   return DSIO_CMD(0x05);
}

//---------------------------------------------------------------
//DSIO_LedOn: Allume la Led
//---------------------------------------------------------------

void DSIO_LedOn(void)
{
   DSIO_CMD(0x06);
}

//---------------------------------------------------------------
//DSIO_LedOff: Eteint la Led
//---------------------------------------------------------------

void DSIO_LedOff(void)
{
	DSIO_CMD(0x07);
}
//----------------------------------------------------------------
//DSIO_Tilt: Detecte Tilt
//----------------------------------------------------------------


u8 DSIO_Tilt(void)
{
   return DSIO_CMD(0x09);
}

//----------------------------------------------------------------------
//DSIO_Axe_X : Retourne valeur hexa de l'orientation de l'axe X
//----------------------------------------------------------------------

u8 DSIO_Axe_X()
{
	u8 temp;
 	DSIO_CMD(0x12);
	swiWaitForVBlank();
 	temp=DSIO_CMD(0x04);
 	return temp;

}

//----------------------------------------------------------------------
//DSIO_Axe_Y : Retourne valeur hexa de l'orientation de l'axe Y
//----------------------------------------------------------------------

u8 DSIO_Axe_Y()
{
	u8 temp;
 	DSIO_CMD(0x11);
	swiWaitForVBlank();
 	temp=DSIO_CMD(0x04);
 	return temp;

}

//----------------------------------------------------------------------
//DSIO_Axe_Z : Retourne valeur hexa de l'orientation de l'axe Z
//----------------------------------------------------------------------

u8 DSIO_Axe_Z()
{
	u8 temp;
 	DSIO_CMD(0x10);
	swiWaitForVBlank();
 	temp=DSIO_CMD(0x04);
 	return temp;

}
