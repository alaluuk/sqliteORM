# ORM (Object-Relational Mapping)

ORM eli Object-Relational Mapping on ohjelmistokehityksen käsite, joka viittaa tekniikkaan, joka mahdollistaa relaatiotietokannan ja sovellusohjelman välisen kommunikoinnin olioiden avulla. 

ORM toimii siten, että se kuvaa tietokannan taulut ohjelmiston olioina, ja tarjoaa ohjelmiston kehittäjille helpon tavan hakea, tallentaa ja päivittää tietoja tietokannasta käyttämällä ohjelmointikielelle tyypillisiä objekteja ja metodeja. Tämä abstraktio tekee tietokannan käytöstä helpompaa ja vähentää suoraa SQL-koodin tarvetta, mikä voi tehdä ohjelmiston kehittämisestä tehokkaampaa ja ylläpidettävämpää. 

Suosittuja ORM-järjestelmiä ovat esimerkiksi **Hibernate** Java-ohjelmoinnissa ja **Entity Framework** .NET-kehityksessä.

Yleensä siis käytetään jotain valmista ORM-kirjastoa. Tässä esimerkissä tein itse alkeellisen version C++ kielellä SQLite-tietokannalle.

## Sovelluksen rakenne

Tietokannan **person-taulu** sisältää kentät 
<ul>
<li>id integer</li>
<li>firstname varchar(45)</li>
<li>lastname varchar(45)</li>
</ul>

**Person-luokka** sisältää kentät
<ul>
<li>int id</li>
<li>QString fname</li>
<li>QString lname </li>
</ul>

**Datacontext**-luokassa on määritetty **objectList** niminen oliolista. Kun Datacontext-luokasta luodaan olio, niin tietokannasta haetaan person-taulun data ja kustakin sen rivistä luodaan olio tuohon listaan.

**Datacontext**-luokan **SetObjectList**-metodissa tehdään tietokannan datan mäppäys oliolistaan nimeltään **objectList**.

**Datacontext**-luokan **GetObjectList**-metodi palauttaa listan kaikki oliot.

**Datacontext**-luokan **GetOnePerson**-metodi palauttaa olion, jonka id täsmää sille annettuun argumenttiin.

**Datacontext**-luokan **AddPerson**-metodi lisää sille argumenttina annetun olion tietokantaan ja oliolistaan.