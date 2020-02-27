import { Service } from './service.model';

export class ServiceReserve {
  private $service: Service;
  private $nbrPersonnes: number;
  constructor(svc: Service, nbr: number) {
    this.$service = svc;
    this.$nbrPersonnes = nbr;
  }

  public get service(): Service {
    return this.$service;
  }

  public get nbrPersonnes(): number {
    return this.$nbrPersonnes;
  }

  public calculerPrix() {
    return this.$service.prix * this.$nbrPersonnes;
  }
}
