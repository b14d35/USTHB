import { Service } from './service.model';

export class ServicePayant extends Service {
  constructor(id: number, prix: number, type: string) {
    super(id, prix, type);
  }
  public getInfos(): string {
    return super.getInfos();
  }
}
