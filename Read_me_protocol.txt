POur tester le protocol, il faut :
 - d�zipper le HeaderLampe.rar dans un dossier nomm� au pr�alabe HeaderLampe.rar dans le dossier libraries de Arduino (Par exemple pour une installation de base le d�zipper dans C:\Program Files\Arduino\libraries)
 - Mettre le dossier projet Dev � l'endroit o� sont enregistrer les sketch Arduino
 -Une fois cela fait lancer ProjetDev.ino. Pour que le protocol marche, il faut une Arduino Mega. Pour tester entrer dans le boardCOM et �crire par exemple (dans la m�me ligne):
{'Motor':{'m4':{'angle':90,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m4':{'angle':8000,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m3':{'angle':90,'speed':40,'direction':'RIGHT','type':'STEPPERS'},'m2':{'angle': 40,'speed':300,'direction':'LEFT','type':'SERVOS'},'m328':{'angle': 40,'speed':300,'direction':'LEFT','type':'SERVOS'}}}";
