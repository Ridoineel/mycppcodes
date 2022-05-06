# Les références:

> Similaire au fonctionnement des pointeurs, lors de la déclaration <br />
> mettre `&` devant le type de la variable revient à transformer cette variable en une <br />
> référence sur une autre variable

```cpp
int age;
int& referenceSurAge(age);
```

# getline && cin

> Si dans le code on utilise `cin` avant d'utiliser `getline`, <br />
> if faut mettre toujour `cin.ignore()` après le `cin`

# Les fonctions

## Passage de paramaètre par référence

```cpp
// Cette fonction modifie la variable n 
// qui la réléférence est passé en paramètre

int function(int& n) {
	n *= 2;

	return n;
} 

// Cette fonction ne peut modifier la variable n 
int function(int const& n) {
	n *= 2; // error

	return n;
} 
```

## En C++ les string chaines de caractère sont modifiable.

```cpp
string rid = "Midoine";
rid[0] = 'R'; // 'M' -> 'R'
```