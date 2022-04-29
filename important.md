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

int function(int& n) {
	n *= 2;

	return n;
} 
