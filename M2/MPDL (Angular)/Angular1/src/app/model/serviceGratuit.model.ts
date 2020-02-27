import { Service } from './service.model';

export class ServiceGratuit extends Service {
  

  constructor(id: number, type: string) {
    super(id, 0, type);
  }
  public getInfos(): string {
    return super.getInfos();
  }
}
