Softan tarkoitus on toimia järjestelmätiedostokansioiden selaajana, josta tuplaklikkaamalla näkee kansion koon.
Tämä sovellus sellaisenaan ei todista ohjelmointitaitojani, mutta enemmänkin sitä että pääsin käsiksi QT:n model-view maailmaan
lyhyellä itseopiskelulla

Se miten halusin saada softan toimimaan, olisi ollut sellainen, joka näyttää treeviewssä suoraan kansioiden kuluttaman tilan.
Tämän tekeminen osoittautui todella vaikeaksi, sillä QT maailma on tekohetkellä itselleni täysin vieras. 
Pitemmän tutkimisen jälkeen havaitsin, että minun pitäisi tehdä oma subclass QAbstractItemModelista jonka rakenteen itse pystyisin määrittelemään.
