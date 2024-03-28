Readme for GeoNames Postal Code files :

allCountries.zip: all supported countries, for CA,NL and UK only the first part of the codes.
The full codes for CA are in the CA_full.csv.zip, same for NL and UK.
<iso countrycode>: country specific subset also included in allCountries.zip
This work is licensed under a Creative Commons Attribution 4.0 License.
This means you can use the dump as long as you give credit to geonames (a link on your website to www.geonames.org is ok)
see http://creativecommons.org/licenses/by/3.0/
UK (GB_full.csv.zip): Contains Royal Mail data Royal Mail copyright and database right 2022.
The Data is provided "as is" without warranty or any representation of accuracy, timeliness or completeness.

This readme describes the GeoNames Postal Code dataset.
The main GeoNames gazetteer data extract is here: http://download.geonames.org/export/dump/


Supported countries: nearly 100 countries are currently supported. New countries area added when the national postal service starts publishing data under a compatible license.

For many countries lat/lng are determined with an algorithm that searches the place names in the main geonames database 
using administrative divisions and numerical vicinity of the postal codes as factors in the disambiguation of place names. 
For postal codes and place name for which no corresponding toponym in the main geonames database could be found an average 
lat/lng of 'neighbouring' postal codes is calculated.
Please let us know if you find any errors in the data set. Thanks

For Chile we have only the first digits of the full postal codes (for copyright reasons)

For Ireland we have only the first letters of the full postal codes (for copyright reasons)

For Malta we have only the first letters of the full postal codes (for copyright reasons)

The Argentina data file contains the first 5 positions of the postal code.

For Brazil only major postal codes are available (only the codes ending with -000 and the major code per municipality).

The data format is tab-delimited text in utf8 encoding, with the following fields :

country code      : iso country code, 2 characters
postal code       : varchar(20)
place name        : varchar(180)
admin name1       : 1. order subdivision (state) varchar(100)
admin code1       : 1. order subdivision (state) varchar(20)
admin name2       : 2. order subdivision (county/province) varchar(100)
admin code2       : 2. order subdivision (county/province) varchar(20)
admin name3       : 3. order subdivision (community) varchar(100)
admin code3       : 3. order subdivision (community) varchar(20)
latitude          : estimated latitude (wgs84)
longitude         : estimated longitude (wgs84)
accuracy          : accuracy of lat/lng from 1=estimated, 4=geonameid, 6=centroid of addresses or shape


Sample Input Command File
filename US.txt
postal 24060
postal 00000
place Blacksburg
county Bib
place I Can't Find You!
county Doesn't Exist Co.
distance 24060 24073
filename GB.txt
postal IM7
distance IM7 XYZ
Below will be the corresponding output. Both positive and negative responses will be shown below.

Output
Here’s what the output would look like for the given sample input file:

filename US.txt
postal 24060
    US  24060   Blacksburg  Virginia    VA  Montgomery  121         37.2563 -80.4347    4
postal 00000
Sorry, postal code 00000 was not found.
place Blacksburg
    US  29702   Blacksburg  South Carolina  SC  Cherokee    021         35.1095 -81.4942    4
    US  24060   Blacksburg  Virginia    VA  Montgomery  121         37.2563 -80.4347    4
    US  24061   Blacksburg  Virginia    VA  Montgomery  121         37.1791 -80.3515    4
    US  24062   Blacksburg  Virginia    VA  Montgomery  121         37.2296 -80.4139    4
    US  24063   Blacksburg  Virginia    VA  Montgomery  121         37.2296 -80.4139    4
county Bib
    US  35034   Brent   Alabama AL  Bibb    007         32.9357 -87.2114    4
    US  35035   Brierfield  Alabama AL  Bibb    007         33.0427 -86.9517    4
    US  35042   Centreville Alabama AL  Bibb    007         32.9503 -87.1192    4
    US  35074   Green Pond  Alabama AL  Bibb    007         33.2027 -87.118 4
    US  35184   West Blocton    Alabama AL  Bibb    007         33.1424 -87.1369    4
    US  35188   Woodstock   Alabama AL  Bibb    007         33.2068 -87.15  4
    US  36792   Randolph    Alabama AL  Bibb    007         32.8888 -86.907 4
    US  36793   Lawley  Alabama AL  Bibb    007         32.8646 -86.9567    4
    US  31052   Lizella Georgia GA  Bibb    021         32.7773 -83.825 4
    US  31201   Macon   Georgia GA  Bibb    021         32.8095 -83.6168    4
    US  31202   Macon   Georgia GA  Bibb    021         32.8407 -83.6324    4
    US  31203   Macon   Georgia GA  Bibb    021         32.8067 -83.6913    4
    US  31204   Macon   Georgia GA  Bibb    021         32.8424 -83.6766    4
    US  31205   Macon   Georgia GA  Bibb    021         32.8067 -83.6913    4
    US  31206   Macon   Georgia GA  Bibb    021         32.7914 -83.679 4
    US  31207   Macon   Georgia GA  Bibb    021         32.8304 -83.6486    4
    US  31208   Macon   Georgia GA  Bibb    021         32.8067 -83.6913    4
    US  31209   Macon   Georgia GA  Bibb    021         32.8067 -83.6913    4
    US  31210   Macon   Georgia GA  Bibb    021         32.8926 -83.7455    4
    US  31211   Macon   Georgia GA  Bibb    021         32.8869 -83.6021    4
    US  31213   Macon   Georgia GA  Bibb    021         32.8393 -83.6388    4
    US  31216   Macon   Georgia GA  Bibb    021         32.7486 -83.7477    4
    US  31217   Macon   Georgia GA  Bibb    021         32.8118 -83.565 4
    US  31220   Macon   Georgia GA  Bibb    021         32.8595 -83.802 4
    US  31221   Macon   Georgia GA  Bibb    021         32.8407 -83.6324    4
    US  31294   Macon   Georgia GA  Bibb    021         32.8407 -83.6324    4
    US  31295   Macon   Georgia GA  Bibb    021         32.8102 -83.569 4
    US  31296   Macon   Georgia GA  Bibb    021         32.8067 -83.6913    4
    US  31297   Macon   Georgia GA  Bibb    021         32.7004 -83.6572    4
place I Can't Find You!
Sorry, place name I Can't Find You! was not found.
county Doesn't Exist Co.
Sorry, county Doesn't Exist Co. was not found.
distance 24060 24073
    US  24060   Blacksburg  Virginia    VA  Montgomery  121         37.2563 -80.4347    4
    US  24073   Christiansburg  Virginia    VA  Montgomery  121         37.1353 -80.4188    4
    Distance: 13.5281 km
filename GB.txt
postal IM7
    GB  IM7 Port e Vullen           Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Ballaugh            Isle of Man IOM         54.3119 -4.5446 4
    GB  IM7 Bride           Isle of Man IOM         54.3826 -4.3892 4
    GB  IM7 Ballasalla          Isle of Man IOM         54.0959 -4.6296 4
    GB  IM7 Andreas         Isle of Man IOM         54.3667 -4.4333 4
    GB  IM7 Cranstal            Isle of Man IOM         54.3956 -4.3695 4
    GB  IM7 Maughold            Isle of Man IOM         54.2988 -4.3184 4
    GB  IM7 Glentruan           Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Jurby West          Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Smeale          Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Dhowin          Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 The Lhen            Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Jurby East          Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Regaby          Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Dreemskerry         Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Dhoon           Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 St Judes            Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Ravensdale          Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Corrany         Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Sulby           Isle of Man IOM         54.3228 -4.4797 4
    GB  IM7 Churchtown          Isle of Man IOM         54.3815 -4.4273 4
    GB  IM7 Dhoor           Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Glen Auldyn         Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Ballajora           Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Sandygate           Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Crawyn          Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 The Cronk           Isle of Man IOM         54.2294 -4.2683 3
    GB  IM7 Sartfield           Isle of Man IOM         54.2294 -4.2683 3 
distance IM7 XYZ                                                                
    GB  IM7 Ballajora           Isle of Man IOM         54.229400 -4.268300 3
Sorry, postal code XYZ was not found. 
