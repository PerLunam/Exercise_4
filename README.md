# Exercise_4

Methoden der Spieleentwicklung IV (100%)
Der Prototyp Ihres Spiels hat mittlerweile einen gewissen Umfang erreicht. Wie bei
Prototypen üblich, haben Sie nur eine rudimentäre Fehlerbehandlung implementiert.
Ausserdem wollen Sie die Art und Weise, wie Gegenstände gespeichert werden,
anpassen. Daher wird es nun Zeit, dass Sie Ihren Prototypen einen grundlegenden
Refactoring (= Überarbeitung des Codes, weitere Informationen dazu finden Sie
beispielsweise hier (https://en.wikipedia.org/wiki/Code_refactoring) bzw. hier
(https://de.wikipedia.org/wiki/Refactoring)) unterziehen, um Ihren Code fit für die weitere
Entwicklung zu machen.
Gegenstände als Heap-Objekte
Bis jetzt wurden Gegenstände als Kopien in den Arrays gespeichert, die das Inventar
bzw. die Ausrüstung repräsentieren. Dies erschwert allerdings die Implementierung von
Gegenständen mit speziellen Eigenschaften über eine entsprechende
Vererbungshierarchie. Die Arrays für Inventar und Ausrüstung können nämlich keine
Kopien von Unterklassen speichern (da ja der Compiler nicht wissen kann, wieviel
Speicherplatz ein Objekt einer Unterklasse benötigt). Ausserdem können wir aufgrund
der Art und Weise, wie wir Gegenstände abspeichern, Polymorphismus nicht so einfach
anwenden.
Daher sollen für zukünfigte Versionen Ihres Spiels die Gegenstände nicht mehr als Kopie,
sondern als Referenz bzw. Pointer gespeichert werden. Die Gegenstände werden in
Zukunft am Heap erzeugt (also mit dem new Operator) und den jeweiligen Funktionen in
Form eines Pointers übergeben.
Die Objektvariablen inventory bzw. gear sollen als Array von Pointern
umgesetzt werden (z.B. Item* inventory[10] )

Funktionen, die Gegenstände zurückgeben, haben nun als Rückgabewert einen
Pointer (z.B. Item* getInventory(int index) ).
Funktionen, die Gegenstände als Eingabeargument erwarten, bekommen nun einen
Pointer übergeben (z.B. int addInventoryItem(Item* item) ).
Die Objektvariable isValid wird nun nicht mehr benötigt. In Zukunft wird ein nicht
belegter Inventar- bzw. Ausrüstungsslot dadurch erkannt, dass im entsprechenden
Arrayeintrag ein Nullpointer gespeichert ist.
Achten Sie darauf, dass keine Speicherlecks entstehen und zerstören Sie
Gegenstände, sobald sie nicht mehr benötigt werden (z.B. in Destruktoren).
Exceptions
Die Fehlerbehandlung soll auf robustere Beine gestellt und mithilfe von Exceptions neu
konzipiert werden.
Alle Funktionen, die auf ein Array zugreifen und die den Array-Index als
Eingabeargument übergeben bekommen (z.B. getInventory() ) sollen im Falle
eines ungültigen Index eine entsprechende Exception werfen.
Beim Versuch des Hinzufügens eines Gegenstands in ein volles Inventar bzw.
Ausrüstung soll eine entsprechende Exception geworfen werden.
Wenn auf einem ungültigen Inventar- bzw. Ausrüstungsslot zugegriffen wird (z.B. bei
getInventory() oder sellItem() ), d.h. der Index ist zwar korrekt, aber an
dieser Stelle ist kein Gegenstand gespeichert, soll eine entsprechende Exception
geworfen werden.
Setter-Methoden sollen eine entsprechende Exception werfen, wenn ein ungültiger
Wert übergeben wird (z.B. negativer Wert bei setGold() ).
Überlegen Sie sich, ob es weitere Stellen in Ihrem Programm gibt, für die eine
Fehlerbehandlung mit Exceptions sinnvoll wäre.
Implementieren Sie eigene Exceptions für jede Fehlerklasse und überlegen Sie sich
eine passende Vererbungshierarchie für Ihre Exceptions.
Fügen Sie in Ihr Programm entsprechende Exception-Handler ein, die
passende Fehlermeldungen ausgeben und dafür sorgen, dass Ihr Programm im
Fehlerfall weiterhin funktioniert.
Implementieren Sie wieder in der main.cpp ein Testprogramm, in dem die Heldin
gegen zwei Feinde kämpft, den Zauberer Pascal und den Kämpfer Matthias. Sorgen Sie
dafür, dass jede Exception einen passenden Exception-Handler findet. Der vom Compiler
installierte Default-Exception-Handler sollte von Ihrem Programm nie verwendet werden.

Fügen Sie in Ihrem Testprogramm auch Testfälle hinzu, die Exceptions provozieren und
implemetieren Sie entsprechende Exception Handler (z.B. Rufen Sie setGold() mit
einem negativen Eingabeparameter auf und implementieren Sie einen dazugehörigen Try-
Catch Block, der eine entsprechende Fehlermeldung im Catch-Block ausgibt).
