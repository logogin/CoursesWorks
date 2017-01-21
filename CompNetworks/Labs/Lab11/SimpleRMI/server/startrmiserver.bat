@echo off
echo Starting RMI Server

C:\j2sdk1.4.1_01\bin\rmic FunctionsImpl
start C:\j2sdk1.4.1_01\bin\rmiregistry
java functionsServer