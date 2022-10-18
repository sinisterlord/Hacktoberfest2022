#Q1
MARKS<-matrix(c(SUB1,SUB2,SUB3),nrow=20,ncol=3)
colnames(MARKS)<-c("SUB1","SUB2","SUB3")
#a
Total_Marks<-apply(MARKS,1,sum)
Total_Marks
#b
MARKS<-cbind(MARKS,Total_Marks)
MARKS
#c
st.err<-function(x) 
{
  sd(x)/sqrt(length(x))
}
apply(MARKS[,1:3],2,st.err)
#d
apply(MARKS,c(1,2),function(x) x+0.25)

#Q2
V1<-MARKS[,1]
V2<-MARKS[,2]
V3<-MARKS[,3]
Marklist<-list(V1,V2,V3)
lapply(Marklist,sum)

#Q3
TOTAL_SUM<-sapply(Marklist,sum)
TOTAL_SUM

#Q4
square<-function(x) {x*x}
sapply(Marklist,square)

#Q5
I<-c(1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4)
MARKS<-cbind(I,MARKS)
tapply(MARKS[,2],MARKS[,1],mean)
tapply(MARKS[,2],MARKS[,1],sd)

#Q6
mapply(function(x,y) x/y,V1,V2)