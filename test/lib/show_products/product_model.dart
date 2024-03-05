import 'dart:ffi';

class Product {
  String name;
  String desription;
  int itensAvaliable;
  Float price;
  List<String> images;
  List<String> avaliableColors;
  List<String> avaliableSizes;

  Product({
    required this.name,
    required this.desription,
    required this.itensAvaliable,
    required this.price,
    required this.images,
    required this.avaliableColors,
    required this.avaliableSizes,
  });
  
 
}
