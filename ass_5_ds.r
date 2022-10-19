#Q1
df<-read.csv("/gurtaransingh01/Desktop/daily_show_guests.csv.xls")
head(df,10)

#Q2
colnames(df)
names(df)
#both the functions above print the column names of the dataframe

colnames(df)<- c('year:YEAR','job:GoogleKnowlege_Occupation','date:Show','category:Group','guest_name:Raw_Guest_List')
names(df)

#Q3
summary(df$`year:YEAR`,df$`date:Show`,df$`guest_name:Raw_Guest_List`)

#Q4
library(dplyr)
df %>% select(!(`year:YEAR`))