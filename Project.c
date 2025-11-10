#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
  char category[30];
  char name[50];
  float price;
}Food;
int main()
{
  FILE *fp, *bill;
  Food menu[200];
  char selectedCategory[30], selectedItem[50];
  int n = 0, qty, i, found, itemsToBuy;
  float amount, total = 0, discount, gst, finalAmount;
  fp = fopen("menu.txt", "r");
  if (fp == NULL)
   {
     printf("Error: Could not open food.txt\n");
     return 1;
   }
   while (fscanf(fp, "%s %s %f", menu[n].category, menu[n].name, &menu[n].price) != EOF)
      {
        n++;
      }
    fclose(fp);
    printf("\nAvailable Categories: Tiffins, Veg, NonVeg, Snacks,Cold-drinks\n");
    printf("Enter category: ");
    scanf("%s", selectedCategory);
    printf("\n----- %s MENU -----\n", selectedCategory);
    printf("%-15s %-10s\n", "Item", "Price");
    printf("-------------------------\n");
    for (i = 0; i < n; i++)
     {
       if (strcmp(menu[i].category, selectedCategory) == 0)
        {
           printf("%-15s Rs. %.2f\n", menu[i].name, menu[i].price);
        }
     } 
     printf("\nHow many different items do you want to buy? ");
     scanf("%d", &itemsToBuy);bill = fopen("food_bill.txt", "w");
     fprintf(bill, "FOOD BILL (%s)\n", selectedCategory);
     fprintf(bill, "-----------------------------------------\n");
     fprintf(bill, "%-15s %-10s %-10s %-10s\n", "Item", "Qty", "Price", "Amount");
     fprintf(bill, "-----------------------------------------\n");
     printf( "FOOD BILL (%s)\n", selectedCategory);
     printf("-----------------------------------------\n");
     printf("%-15s %-10s %-10s %-10s\n", "Item", "Qty", "Price", "Amount");
     printf("-----------------------------------------\n");
     for (int k = 0; k < itemsToBuy; k++)
      {
        printf("\nEnter Item Name: ");
        scanf("%s", selectedItem);
        found = 0;
        for (i = 0; i < n; i++)
         {
           if (strcmp(menu[i].category, selectedCategory) == 0 && strcmp(menu[i].name, selectedItem) == 0)
            {
              found = 1;
              printf("Enter Quantity: ");
              scanf("%d", &qty);
              amount = qty * menu[i].price;
              total += amount;
              printf("%-15s %-10d %-10.2f %-10.2f\n", menu[i].name, qty, menu[i].price, amount);
              fprintf(bill, "%-15s %-10d %-10.2f %-10.2f\n", menu[i].name, qty, menu[i].price, amount);
              break;
            }
         }
         if (!found)
          {
            printf("Item not found in this category, try again.\n");
            k--; 
          }
       }
       discount = total * 0.10; 
       gst = (total - discount) * 0.05; 
       finalAmount = total - discount + gst;
       fprintf(bill, "-----------------------------------------\n");
       fprintf(bill, "Total Before Discount : %.2f\n", total);
       fprintf(bill, "Discount (10%%) : - %.2f\n", discount);
       fprintf(bill, "GST (5%%) : + %.2f\n", gst);
       fprintf(bill, "-----------------------------------------\n");
       fprintf(bill, "FINAL AMOUNT TO PAY : %.2f\n", finalAmount);
       printf("-----------------------------------------\n");
       printf("Total Before Discount : %.2f\n", total);
       printf("Discount (10%%) : - %.2f\n", discount);
       printf("GST (5%%) : + %.2f\n", gst);
       printf("-----------------------------------------\n");
       printf("FINAL AMOUNT TO PAY : %.2f\n", finalAmount);
       fclose(bill);
       printf("\nFINAL AMOUNT TO PAY: %.2f\n", finalAmount);
       printf("Bill saved in **food_bill.txt**\n");
       printf("Thank You Visit Again\n");
       return 0;
}
