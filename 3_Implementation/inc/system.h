#include<stdio.h>
 #include<string.h>
 #include<ctype.h>
 struct Medicine{
   int id,price,quantity;
   char medicneName[100],Company[100],Mfg_Date[11],Exp_Date[11],info[5000];
  }m[100];
 void PurchaseMedicine(int number);
 void EnterInfoAboutMedicine(int number);
 void StockOfMedicine(int number);
 void KnowInfoAboutMedicine(int number);
 void AddMedicineinStore(int number,struct Medicine m[]);
 void DeleteMedicineStore(int number);
 void ChangeMedicineDetails(int number);
