#include "cereal.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

class SubData
{
    public:
        int a, b, c;
        std::string d;

        template <class Archive>
        void serialize(Archive & ar)
        {
            ar(a, b, c, d); // serialize things by passing them to the archive
        }
};

class Data
{
    public:
    int x, y, z;
    std::string name;
    std::vector<int> data;
    SubData sub;

    template <class Archive>
    void save(Archive & archive) const
    {
        archive(x, y, z); // serialize things by passing them to the archive
        archive(name);
        archive(data);
        archive(sub);
    }

    template <class Archive>
    void load(Archive & archive)
    {
        archive(x, y, z); // serialize things by passing them to the archive
        archive(name);
        archive(data);
        archive(sub);
    }
};

void setup()
{
      Serial.begin(115200);
      while ( !Serial ) delay(10);

      Serial.println("Cereal Example");
      Serial.println();

      // Wait for user input to run.
      Serial.print("Enter any keys to continue:");
      while ( !Serial.available() )
      {
        delay(1);
      }
      Serial.println();
      Serial.println();

    SubData sub = {1, 2, 3, "sub"};
    Data d = { 1, 2, 3, "Test", {1, 2, 3, 4, 5}, sub};

    std::stringstream ss;
    {
        cereal::BinaryOutputArchive oarchive( ss );
        oarchive( d );
    }
    Serial.println("BinaryOutputArchive:");
    Serial.println(ss.str().c_str());
    Serial.println("Archive size (bytes):");
    Serial.println(sizeof(ss));

    Data d2;
    {
        cereal::BinaryInputArchive iarchive( ss );
        iarchive( d2 );
    }

    Serial.println("Deserialized Data:");
    Serial.print("x: ");
    Serial.println(d2.x);
    Serial.print("y: ");
    Serial.println(d2.y);
    Serial.print("z: ");
    Serial.println(d2.z);
    Serial.print("name: ");
    Serial.println(d2.name.c_str());
    Serial.print("data: ");
    for (auto i : d2.data)
    {
        Serial.print(i);
        Serial.print(" ");
    }
    Serial.println();
    Serial.print("sub.a: ");
    Serial.println(d2.sub.a);
    Serial.print("sub.b: ");
    Serial.println(d2.sub.b);
    Serial.print("sub.c: ");
    Serial.println(d2.sub.c);
    Serial.print("sub.d: ");
    Serial.println(d2.sub.d.c_str());
}
