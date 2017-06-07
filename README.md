# STM_BeerOpener
Naszym projektem był otwieracz do butelek. Chcieliśmy zrealizować prosty otwieracz, 
który po przyłożeniu butelki za pomocą siłownika liniowego podważy kapsel otwierając butelkę.

Opis:
	Użyty sprzęt: 
		STM32F4 Discovery,
		Siłownik liniowy 12V 7kg - 5-przewodowy,
		Dwukanałowy moduł przekaźników RM5 z izolacją optoelektroniczną 5V 10A/125VAC,
		Czujnik siły nacisku okrągły 13mm (0,6''),
		Dodatkowy zasliacz przeznaczony dla siłownika.
	
	Obsługa siłownika i czujnika siły nacisku zostały zrealizowane na STM32

	Wstępny wygląd projektu został zaprojektowany w programie Autodesk Inventor, jednak podczas bardziej
	praktycznych prób jego wykonania zostaliśmy zmuszeni do zmiany naszysz założeń

	Cel projektu: poszerzenie naszej wiedy o mikrokontrolerach oraz umiejętności pracy z nimi 
	      i różnymi modułami

Narzędzia: 
	CooCox CoIDE wersja 1.7.8 http://www.coocox.org/CooCox_CoIDE.htm
	Autodesk Inventor 2016 https://www.autodesk.com/education/free-software/inventor-professional
	Język C

Uruchamianie:
	Release 0.1
	Aby uruchomić otwieracz potrzebne jest dodatkowe zasilanie z sieci przeznaczone dla słownika.

Sposoby ulepszenia:
	W celu usprawnienia działania otwieracza warto byłoby zastosować bardziej kompatybilny siłownik
	liniowy, gdyż obecnie zastosowany, po dłuższym czasie pracy emituje wysokie temperatury.
	Przydatną modyfikacją byłoby dodanie specjalnego "ramienia", które mogłoby przytrzymać butelkę.

Przypisy:
	https://create.arduino.cc/projecthub/robotgeek-projects-team/control-a-large-linear-actuator-with-arduino-8a3953
	


Credits
The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering,
Poznan University of Technology.
Supervisor: mgr inż. Adam Bondyra


Copyright (c) 2017 Sobieszczyk Mateusz & Wojciechowski Aleksander
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

