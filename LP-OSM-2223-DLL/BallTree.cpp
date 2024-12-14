#include "pch.h"
#include "BallTree.h"

void BallTree::construirArbre(const std::vector<Coordinate>& coordenades) {
    // TODO: Utilitza aquest metode per construir el teu BallTree
    // TODO: amb les coordenades que se us passen per parametre
    m_coordenades = coordenades;
    m_pivot = calculaPuntC(coordenades);    
    std::vector<double> distanciesPivot = calculaDistancies(coordenades, m_pivot);
    Coordinate puntA = puntMesLlunya(coordenades, distanciesPivot);
    m_radi = Util::DistanciaHaversine(puntA, m_pivot);
    if (coordenades.size() == 1)                                //Quan ja tenim el radi ja pot ser fulla.
    {
        return;
    }
    std::vector<double> distanciesPuntA = calculaDistancies(coordenades, puntA);
    Coordinate puntB = puntMesLlunya(coordenades, distanciesPuntA);

    std::vector<Coordinate> esquerra, dreta;
    for (auto it = coordenades.begin(); it != coordenades.end(); it++)
    {
        double d1 = Util::DistanciaHaversine((*it), puntA), d2 = Util::DistanciaHaversine((*it), puntB);
        if (d1 < d2)
            esquerra.push_back(*it);           //Afegim el node a la llista de la bola esquerra
        else
            dreta.push_back(*it);          //Afegim el node a la llista de la bola dreta
    }

    if (!esquerra.empty())
    {
        m_left = new BallTree();
        m_left->construirArbre(esquerra);
    }

    if (!dreta.empty())
    {
        m_right = new BallTree();
        m_right->construirArbre(dreta);
    }
}

void BallTree::inOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
    if (m_left != nullptr) m_left->inOrdre(out);
    if (!m_coordenades.empty()) out.emplace_back(m_coordenades.begin(), m_coordenades.end());
    if (m_right != nullptr) m_right->inOrdre(out);

}
void BallTree::preOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
    if (!m_coordenades.empty()) out.emplace_back(m_coordenades.begin(), m_coordenades.end());
    if (m_left != nullptr) m_left->inOrdre(out);
    if (m_right != nullptr) m_right->inOrdre(out);
}

void BallTree::postOrdre(std::vector<std::list<Coordinate>>& out) {
    // TODO: TASCA 2
    if (m_left != nullptr) m_left->inOrdre(out);
    if (m_right != nullptr) m_right->inOrdre(out);
    if (!m_coordenades.empty()) out.emplace_back(m_coordenades.begin(), m_coordenades.end());
}

Coordinate BallTree::calculaPuntC(const std::vector<Coordinate>& coordenades)
{
    double sumLat = 0.0, sumLon = 0.0;
    int nElms = coordenades.size();
    for (auto it = coordenades.begin(); it < coordenades.end(); it++)
    {
        sumLat += it->lat;
        sumLon += it->lon;
    }
    return { sumLat / nElms, sumLon / nElms };
}

std::vector<double> BallTree::calculaDistancies(const std::vector<Coordinate>& coordenades, const Coordinate& inicial )
{
    std::vector<double> result;
    for (auto it = coordenades.begin(); it < coordenades.end(); it++)
    {
        result.emplace_back(Util::DistanciaHaversine((*it), inicial));
    }
    return result;
}

Coordinate BallTree::puntMesLlunya(const std::vector<Coordinate>& coordenades, const std::vector<double>& distancies)
{
    size_t ind = 0;
    double maxDist = distancies[0];
    for (auto it = distancies.begin(); it < distancies.end(); it++)
    {
        if ((*it) > maxDist)
        {
            maxDist = (*it);
            ind = std::distance(distancies.begin(), it);
        }
    }
    return coordenades[ind];
}

Coordinate BallTree::nodeMesProper(Coordinate targetQuery, Coordinate& Q, BallTree* ball) 
{
    // TODO: TASCA 3
    return Coordinate();
}



