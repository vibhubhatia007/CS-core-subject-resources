# -*- coding: utf-8 -*-
"""
Created on Mon May 25 19:16:10 2020

@author: Dell

basic it workshop assignment
by-vibhu bhatia
roll no-btech/10669/18
"""
import numpy as np

#Weight Initialisation
v11= 0.6 
v21= -0.1
v01= 0.3
v12= -0.3
v22=  0.4
v02 = 0.5

#Hiddernlayer weights
w1 = 0.4
w2= 0.1
w0 = -0.2
alpha = 0.5
epoch = 0

xor = [[0,0 , 1] , [0,1,1] ,[1,0,1],[1,1,0] ]

#Bipolar sigmoidal
def f(x):
    return 1/(1+np.exp(-x))


for row in xor:
    print("-------------START EPOCH " + str(epoch) +" ----------- ")
    x1= row[0] +0.0
    x2= row[1] +0.0
    t=  row[2] +0.0
    #Feed forward
    zin1 = v11*x1+v21*x2+v01
    zin2 = v21*x1+v22*x2+v02
    z1= f(zin1)
    z2= f(zin2)
    yin= z1*w1+z2*w2+w0
    y = f(yin) #Predicted y

    #Backprop
    
    Del1 = (t- y)*(y*(1-y))  #Formula original  => Delk = [tk-yk]*f'(yink)

    delta_w1 = alpha*Del1*z1                #Original formula = deltawi = alpha*deltai*zi  
    delta_w2 = alpha*Del1*z2
    delta_w0 = alpha*Del1

    Del_jin1= Del1*w1        # E1 = Deljin1*f'(z1)
    Del_jin2= Del1*w2        # E2 = Deljin2*f'(z2)  
    dx_z1 = z1*(1-z1)         # f'(z1)
    dx_z2 = z2*(1-z2)         # f'(z2)

    delE1 = Del_jin1*dx_z1
    delE2 = Del_jin2*dx_z2

    delv11 = alpha*delE1*x1
    delv21 = alpha*delE1*x2
    delv01 = alpha*delE1

    delv12 = alpha*delE2*x1
    delv22 = alpha*delE2*x2
    delv02 = alpha*delE2


    print("x1 - " , x1)
    print("x2 - " , x2)
    print("t - " , t)
    print("zin1 - " , zin1)
    print("zin2 - " , zin2)
    print("z1 - " , z1)
    print("z2- " , z2)
    print("yin - " , yin)
    print("y - " , y)
    print("Del1 - " , Del1)
    print("delta_w1 - " , delta_w1)
    print("delta_w2 - " , delta_w2)
    print("delta_w0 - " , delta_w0)
    print("delE1 - " , delE1)
    print("delE2 - " , delE2)
    

    #Final weight updation
    v11+=delv11
    v21+=delv21
    v01+=delv01

    v12+=delv12
    v22+=delv22
    v02+=delv02

    w1+=delta_w1
    w2+=delta_w2
    w0+=delta_w0

    print("v11_new - ", v11)
    print("v21_new - ", v21)
    print("v01_new - ", v01)
    print("v12_new - ", v12)
    print("v22_new - ", v22)
    print("v02_new - ", v02)
    print("w1_new - ", w1)
    print("w2_new - ", w2)
    print("w0_new - ", w0)

    print("-----------------------------END OF EPOCH "+ str(epoch) + "---------------")
    epoch+=1
    
