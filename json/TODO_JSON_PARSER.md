# 📋 TODO - Parser JSON - Plan d'implémentation complet

## 🎯 **VUE D'ENSEMBLE**
Basé sur le fichier `include/json.h`, voici le plan d'implémentation complet du parser JSON organisé par priorités et parties.

---

## 🚨 **PRIORITÉ 1 - FONDATIONS (OBLIGATOIRE)**

### **1.1 Structures de base et types**
- [ ] **Implémenter les enums** dans `src/json/types.c`
  - [ ] `e_token_type` - Types de tokens
  - [ ] `e_json_type` - Types de nœuds JSON
  - [ ] `e_json_error` - Codes d'erreur

### **1.2 Gestion mémoire de base**
- [ ] **`src/json/memory.c`**
  - [ ] `json_cleanup_value()` - Nettoyage des valeurs JSON
  - [ ] `json_clone_value()` - Copie profonde des valeurs
  - [ ] `json_error_string()` - Conversion erreur → string

### **1.3 Création de nœuds**
- [ ] **`src/json/node_creation.c`**
  - [ ] `json_node_new()` - Création nœud de base
  - [ ] `json_node_destroy()` - Destruction récursive
  - [ ] `json_node_clone()` - Copie profonde
  - [ ] `json_node_set_key()` - Définir clé
  - [ ] `json_node_set_value()` - Définir valeur

### **1.4 Helpers de création**
- [ ] **`src/json/node_helpers.c`**
  - [ ] `json_create_string()` - Nœud string
  - [ ] `json_create_number()` - Nœud nombre
  - [ ] `json_create_bool()` - Nœud booléen
  - [ ] `json_create_null()` - Nœud null
  - [ ] `json_create_object()` - Nœud objet
  - [ ] `json_create_array()` - Nœud tableau

---

## 🔧 **PRIORITÉ 2 - LEXER (TOKENIZATION)**

### **2.1 Lexer de base**
- [ ] **`src/json/lexer.c`**
  - [ ] `json_lexer_new()` - Initialisation lexer
  - [ ] `json_lexer_destroy()` - Destruction lexer
  - [ ] `json_skip_whitespace()` - Ignorer espaces/tabs/newlines
  - [ ] `json_get_next_token()` - Token suivant
  - [ ] `json_peek_token()` - Regarder sans consommer

### **2.2 Parsing de tokens spécifiques**
- [ ] **`src/json/token_parsers.c`**
  - [ ] `json_parse_string()` - Chaînes avec échappement
  - [ ] `json_parse_number()` - Nombres (int/float)
  - [ ] `json_parse_bool()` - true/false
  - [ ] `json_parse_null()` - null
  - [ ] `json_parse_punctuation()` - {}, [], :, ,

### **2.3 Gestion d'erreurs lexer**
- [ ] **`src/json/lexer_errors.c`**
  - [ ] Détection chaînes non terminées
  - [ ] Détection échappements invalides
  - [ ] Détection nombres malformés
  - [ ] Position ligne/colonne des erreurs

---

## 🧠 **PRIORITÉ 3 - PARSER (AST CONSTRUCTION)**

### **3.1 Parser principal**
- [ ] **`src/json/parser.c`**
  - [ ] `json_parser_new()` - Initialisation parser
  - [ ] `json_parser_destroy()` - Destruction parser
  - [ ] `json_parse()` - Fonction principale
  - [ ] `json_parse_value()` - Parser valeur générique

### **3.2 Parsers spécifiques**
- [ ] **`src/json/parsers.c`**
  - [ ] `json_parse_object()` - Objets `{}`
  - [ ] `json_parse_array()` - Tableaux `[]`
  - [ ] `json_parse_property()` - Propriétés d'objet
  - [ ] `json_parse_element()` - Éléments de tableau

### **3.3 Gestion d'erreurs parser**
- [ ] **`src/json/parser_errors.c`**
  - [ ] `json_get_last_error()` - Récupérer dernière erreur
  - [ ] `json_get_error_message()` - Message d'erreur
  - [ ] Détection tokens inattendus
  - [ ] Détection objets/tableaux non fermés
  - [ ] Détection virgules trailing

---

## 🔍 **PRIORITÉ 4 - NAVIGATION ET ACCÈS**

### **4.1 Fonctions d'accès**
- [ ] **`src/json/access.c`**
  - [ ] `json_node_get_child()` - Enfant par index
  - [ ] `json_node_get_by_key()` - Enfant par clé
  - [ ] `json_node_child_count()` - Nombre d'enfants
  - [ ] `json_node_is_leaf()` - Vérifier si feuille
  - [ ] `json_node_add_child()` - Ajouter enfant

### **4.2 Fonctions de manipulation**
- [ ] **`src/json/manipulation.c`**
  - [ ] `json_get()` - Accéder par chemin
  - [ ] `json_set()` - Définir valeur
  - [ ] `json_delete()` - Supprimer clé
  - [ ] `json_merge()` - Fusionner objets

### **4.3 Getters typés**
- [ ] **`src/json/getters.c`**
  - [ ] `json_get_string()` - Récupérer string
  - [ ] `json_get_number()` - Récupérer nombre
  - [ ] `json_get_bool()` - Récupérer booléen
  - [ ] `json_is_null()` - Vérifier si null

---

## 📄 **PRIORITÉ 5 - SÉRIALISATION**

### **5.1 Sérialisation de base**
- [ ] **`src/json/serialization.c`**
  - [ ] `json_to_string()` - Conversion en string
  - [ ] `json_minify()` - Version compacte
  - [ ] `json_pretty_print()` - Version formatée

### **5.2 Formatage**
- [ ] **`src/json/formatting.c`**
  - [ ] Gestion indentation
  - [ ] Échappement des caractères spéciaux
  - [ ] Formatage des nombres
  - [ ] Gestion des espaces

### **5.3 Opérations fichier**
- [ ] **`src/json/file_ops.c`**
  - [ ] `json_from_file()` - Charger depuis fichier
  - [ ] `json_to_file()` - Sauvegarder dans fichier
  - [ ] Gestion erreurs I/O
  - [ ] Validation encodage UTF-8

---

## ✅ **PRIORITÉ 6 - VALIDATION ET UTILITAIRES**

### **6.1 Validation**
- [ ] **`src/json/validation.c`**
  - [ ] `json_validate()` - Validation syntaxe
  - [ ] Validation schéma (optionnel)
  - [ ] Détection cycles (pour objets circulaires)

### **6.2 Fonctions utilitaires**
- [ ] **`src/json/utilities.c`**
  - [ ] `json_object()` - Créer objet avec varargs
  - [ ] `json_array()` - Créer tableau avec varargs
  - [ ] `json_path_get()` - Accès par chemin JSONPath
  - [ ] `json_transform()` - Transformer nœuds

---

## 🧪 **PRIORITÉ 7 - TESTS ET DEBUG**

### **7.1 Tests unitaires**
- [ ] **`tests/test_lexer.c`**
  - [ ] Tests tous types de tokens
  - [ ] Tests erreurs lexer
  - [ ] Tests position ligne/colonne

- [ ] **`tests/test_parser.c`**
  - [ ] Tests parsing objets
  - [ ] Tests parsing tableaux
  - [ ] Tests parsing valeurs primitives
  - [ ] Tests erreurs parser

- [ ] **`tests/test_serialization.c`**
  - [ ] Tests sérialisation
  - [ ] Tests pretty print
  - [ ] Tests minification

### **7.2 Tests d'intégration**
- [ ] **`tests/test_integration.c`**
  - [ ] Tests fichiers JSON réels
  - [ ] Tests performance
  - [ ] Tests mémoire (valgrind)

### **7.3 Tests d'erreurs**
- [ ] **`tests/test_errors.c`**
  - [ ] Tests syntaxe invalide
  - [ ] Tests fichiers corrompus
  - [ ] Tests limites (fichiers très gros)

---

## 🚀 **PRIORITÉ 8 - OPTIMISATIONS ET FEATURES AVANCÉES**

### **8.1 Optimisations**
- [ ] **`src/json/optimizations.c`**
  - [ ] Pool de tokens
  - [ ] Cache de parsing
  - [ ] Allocation par blocs
  - [ ] Streaming pour gros fichiers

### **8.2 Features avancées**
- [ ] **`src/json/advanced.c`**
  - [ ] Support JSONPath
  - [ ] Support JSON Schema
  - [ ] Support JSON Patch
  - [ ] Support JSON Merge Patch

### **8.3 Extensions**
- [ ] **`src/json/extensions.c`**
  - [ ] Support commentaires (JSONC)
  - [ ] Support trailing commas
  - [ ] Support nombres hexadécimaux
  - [ ] Support dates ISO 8601

---

## 📁 **STRUCTURE DES FICHIERS**

```
src/json/
├── types.c              # Enums et types
├── memory.c             # Gestion mémoire
├── node_creation.c      # Création nœuds
├── node_helpers.c       # Helpers création
├── lexer.c              # Lexer principal
├── token_parsers.c      # Parsing tokens
├── lexer_errors.c       # Erreurs lexer
├── parser.c             # Parser principal
├── parsers.c            # Parsers spécifiques
├── parser_errors.c      # Erreurs parser
├── access.c             # Accès nœuds
├── manipulation.c       # Manipulation
├── getters.c            # Getters typés
├── serialization.c      # Sérialisation
├── formatting.c         # Formatage
├── file_ops.c           # Opérations fichier
├── validation.c         # Validation
├── utilities.c          # Utilitaires
├── optimizations.c      # Optimisations
├── advanced.c           # Features avancées
└── extensions.c         # Extensions

tests/
├── test_lexer.c
├── test_parser.c
├── test_serialization.c
├── test_integration.c
└── test_errors.c

include/
└── json.h               # Header principal
```

---

## 🎯 **ORDRE D'IMPLÉMENTATION RECOMMANDÉ**

1. **Semaine 1** : Priorité 1 (Fondations)
2. **Semaine 2** : Priorité 2 (Lexer)
3. **Semaine 3** : Priorité 3 (Parser)
4. **Semaine 4** : Priorité 4 (Navigation)
5. **Semaine 5** : Priorité 5 (Sérialisation)
6. **Semaine 6** : Priorité 6 (Validation)
7. **Semaine 7** : Priorité 7 (Tests)
8. **Semaine 8** : Priorité 8 (Optimisations)

---

## ⚠️ **POINTS D'ATTENTION**

### **Critiques**
- [ ] **Gestion mémoire** - Pas de fuites avec valgrind
- [ ] **Gestion d'erreurs** - Messages clairs et position précise
- [ ] **Performance** - Support fichiers volumineux
- [ ] **Robustesse** - Gestion fichiers corrompus

### **Bonnes pratiques**
- [ ] **Documentation** - Commentaires Doxygen complets
- [ ] **Tests** - Couverture > 90%
- [ ] **Style** - Respect norme 42
- [ ] **Modularité** - Fonctions courtes et réutilisables

---

## 🎉 **CRITÈRES DE SUCCÈS**

- [ ] Parse tous les fichiers JSON valides
- [ ] Gère correctement tous les types d'erreurs
- [ ] Performance acceptable (< 1s pour 1MB)
- [ ] Pas de fuites mémoire
- [ ] Tests passent à 100%
- [ ] Documentation complète
- [ ] Compatible avec libft existante

---

**Status global :** 🟡 En cours  
**Progression :** 0% (0/150 tâches complétées)  
**Prochaine étape :** Implémenter les structures de base (Priorité 1.1) 
