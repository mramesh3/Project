#   Program to obtain earnings on a particular date
#   or a range of date 

#   Documentation for the yahoo finance library
#   http://theautomatic.net/yahoo_fin-documentation/#methods

#   Author: Mahendri Ramesh
#   Date: 08/29/2021    
########################################################
#   Libraries
########################################################
import yahoo_fin.stock_info as info
import pandas as pd 
import openpyxl
from openpyxl import *
import xlsxwriter
import csv

########################################################
#   Function
########################################################

#To obtain earnings on a particular date
def dateEarnings():
    gDE = input("Enter date in format YYYY-MM-DD: ")
    df1 = pd.DataFrame(info.get_earnings_for_date(gDE))
    writer = pd.ExcelWriter("dateEarnings.xlsx",engine = 'xlsxwriter')
    df1.to_excel(writer, sheet_name = 'Earnings')
    writer.save()
    #print(df1)
#Need to check for error handling
    print("Date earnings retrieval success\n Check in dateEarnings.xlsx")
    


#To obtain earnings for a range of dates
def rangeEarnings():
    gRE1 = input("Enter date in format MM/DD/YYYY: ")
    gRE2 = input("Enter date in format MM/DD/YYYY: ")
    earnings_in_week = info.get_earnings_in_date_range(gRE1, gRE2)
    df2 = pd.DataFrame(earnings_in_week)
    #print(df2)
    writer = pd.ExcelWriter("rangeEarnings.xlsx",engine = 'xlsxwriter')
    df2.to_excel(writer, sheet_name = 'Earnings')
    writer.save()
#Need to check for error handling
    print("Range earnings retrieval success\n Check in rangeEarnings.xlsx")



#main function
def main(g1):
    if g1 == '1':
        dateEarnings()
    elif g1 == '2':
        rangeEarnings()

if __name__ == "__main__":
    print("Menu options: \n")
    print("1) Date earnings\n")
    print("2) Range earnings\n")
    print("3) Exit\n")
    g1 = input("Enter option: ")
    if g1 =='3':
        exit()
    elif g1=='1' | g1 == '2':
        main(g1)
    # need to include error conditions 


########################   END   ######################

